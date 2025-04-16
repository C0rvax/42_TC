// plugins/auth.js
const fp = require('fastify-plugin');
const jwt = require('@fastify/jwt');

async function authPlugin(fastify, options) {
  fastify.register(jwt, {
    secret: process.env.JWT_SECRET,
    cookie: { // Optional: if you want to use cookies
      cookieName: 'token',
      signed: false // Use true if you sign cookies separately
    }
  });

  // Decorator to easily protect routes
  fastify.decorate('authenticate', async function(request, reply) {
    try {
      await request.jwtVerify();
    } catch (err) {
      reply.code(401).send({ message: 'Unauthorized: Invalid or missing token', error: err.message });
    }
  });
}

module.exports = fp(authPlugin);
