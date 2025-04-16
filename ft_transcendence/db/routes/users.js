 // routes/users.js

async function userRoutes(fastify, options) {
  const knex = fastify.knex;

  // Get logged-in user's profile
  fastify.get('/me', { preHandler: [fastify.authenticate] }, async (request, reply) => {
    const userId = request.user.id; // From JWT payload

    try {
      const userProfile = await knex('users')
        .select('id', 'username', 'email', 'display_name', 'avatar_url', 'wins', 'losses', 'status', 'created_at') // Exclude password_hash!
        .where({ id: userId })
        .first();

      if (!userProfile) {
        throw fastify.httpErrors.notFound('User not found');
      }
      reply.send(userProfile);
    } catch (err) {
      request.log.error(err);
       if (err.statusCode) {
           reply.code(err.statusCode).send({ message: err.message });
       } else {
           reply.code(500).send({ message: 'Error fetching profile' });
       }
    }
  });

  // --- Add PUT /me for updates ---
  // --- Add POST /me/avatar for upload ---
  // --- Add GET /:userId/profile for public profiles ---
  // --- Add GET /:userId/matches for match history ---

}

module.exports = userRoutes;
