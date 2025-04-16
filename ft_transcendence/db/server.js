// server.js
require('dotenv').config();
const path = require('path');
const Fastify = require('fastify');

const fastify = Fastify({
  logger: true // Enable logging
});

// Register essential plugins
fastify.register(require('@fastify/cors'), { origin: '*' /* Configure properly for production */ });
fastify.register(require('@fastify/sensible'));
fastify.register(require('@fastify/cookie')); // Needed for JWT cookie support if used
fastify.register(require('@fastify/multipart')); // For avatar uploads

// Register custom plugins
fastify.register(require('./plugins/db'));
fastify.register(require('./plugins/auth'));

// Register WebSocket plugin *before* WebSocket routes
fastify.register(require('fastify-websocket'));

// Register routes
fastify.register(require('./routes/auth'), { prefix: '/api/auth' });
fastify.register(require('./routes/users'), { prefix: '/api/users' });
fastify.register(require('./routes/friends'), { prefix: '/api/friends' });
fastify.register(require('./routes/ws'), { prefix: '/ws' }); // WebSocket endpoint

// Simple health check route
fastify.get('/ping', async (request, reply) => {
  return { pong: 'it worked!' };
});

// Start the server
const start = async () => {
  try {
    await fastify.listen({ port: process.env.PORT || 3000, host: '0.0.0.0' }); // Listen on all interfaces for Docker
  } catch (err) {
    fastify.log.error(err);
    process.exit(1);
  }
};
start();
