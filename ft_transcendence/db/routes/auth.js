 
// routes/auth.js
const bcrypt = require('bcrypt');
const saltRounds = 10; // Cost factor for bcrypt

// Basic validation schema (consider using Zod for more complex validation)
const registerSchema = {
  body: {
    type: 'object',
    required: ['username', 'email', 'password', 'display_name'],
    properties: {
      username: { type: 'string', minLength: 3 },
      email: { type: 'string', format: 'email' },
      password: { type: 'string', minLength: 6 },
      display_name: { type: 'string', minLength: 3 }
    }
  }
};

async function authRoutes(fastify, options) {

  fastify.post('/register', { schema: registerSchema }, async (request, reply) => {
    const { username, email, password, display_name } = request.body;
    const knex = fastify.knex; // Access Knex instance

    try {
      // Check for existing user/email (handle potential race conditions in production)
      const existingUser = await knex('users')
        .where({ username })
        .orWhere({ email })
        .orWhere({ display_name })
        .first();

      if (existingUser) {
        // Be specific about the conflict if possible, but avoid revealing too much
        if (existingUser.username === username) throw fastify.httpErrors.conflict('Username already exists');
        if (existingUser.email === email) throw fastify.httpErrors.conflict('Email already registered');
        if (existingUser.display_name === display_name) throw fastify.httpErrors.conflict('Display name already taken');
      }

      // Hash the password
      const password_hash = await bcrypt.hash(password, saltRounds);

      // Insert the new user
      const [newUser] = await knex('users')
        .insert({
          username,
          email,
          password_hash,
          display_name,
        })
        .returning(['id', 'username', 'email', 'display_name', 'created_at']); // Return some user data

      reply.code(201).send({ message: 'User registered successfully', user: newUser });

    } catch (err) {
      // Log the detailed error internally
      request.log.error(err);
      // Send a generic or specific error response
      if (err.statusCode) { // If it's a pre-defined Fastify HTTP error
         reply.code(err.statusCode).send({ message: err.message });
      } else {
         reply.code(500).send({ message: 'Registration failed due to an internal error.' });
      }
    }
  });

  // --- LOGIN ROUTE ---
  const loginSchema = {
    body: {
      type: 'object',
      required: ['login', 'password'], // 'login' can be username or email
      properties: {
        login: { type: 'string' },
        password: { type: 'string' }
      }
    }
  };
  fastify.post('/login', { schema: loginSchema } ,async (request, reply) => {
      const { login, password } = request.body;
      const knex = fastify.knex;

      try {
          const user = await knex('users')
              .where('username', login)
              .orWhere('email', login)
              .first();

          if (!user) {
              throw fastify.httpErrors.unauthorized('Invalid credentials');
          }

          const match = await bcrypt.compare(password, user.password_hash);

          if (!match) {
              throw fastify.httpErrors.unauthorized('Invalid credentials');
          }

          // --- Generate JWT ---
          const tokenPayload = {
              id: user.id,
              username: user.username,
              // Add other non-sensitive info if needed
          };
          const token = await reply.jwtSign(tokenPayload, { expiresIn: '1h' }); // Token expires in 1 hour

          // Update status to 'online' (potentially via WebSocket later)
          await knex('users').where({ id: user.id }).update({ status: 'online', updated_at: knex.fn.now() });
          // Notify friends via WebSocket here if implemented

           // Send token back to client
          reply.send({ message: 'Login successful', token: token, userId: user.id });

      } catch(err) {
          request.log.error(err);
          if (err.statusCode) {
              reply.code(err.statusCode).send({ message: err.message });
          } else {
              reply.code(500).send({ message: 'Login failed due to an internal error.' });
          }
      }
  });


  // --- LOGOUT ROUTE --- (Needs authentication)
  fastify.post('/logout', { preHandler: [fastify.authenticate] }, async (request, reply) => {
      const userId = request.user.id; // Decoded from JWT by preHandler
      const knex = fastify.knex;

      try {
          // Update status to offline
          await knex('users').where({ id: userId }).update({ status: 'offline', updated_at: knex.fn.now() });
          // Notify friends via WebSocket here if implemented

          // Client side should discard the token upon receiving success
          reply.send({ message: 'Logout successful' });

      } catch (err) {
          request.log.error(err);
          reply.code(500).send({ message: 'Logout failed' });
      }
  });

  // Add other auth-related routes if needed (e.g., password reset)
}

module.exports = authRoutes;
