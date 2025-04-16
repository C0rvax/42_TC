// server.js
const path = require('path');
const fastify = require('fastify')({ logger: true });
const fastifyStatic = require('@fastify/static');

// Sert les fichiers statiques (SPA)
fastify.register(fastifyStatic, {
  root: path.join(__dirname, 'public'),
  wildcard: false,
});

// Catch-all route pour la SPA (utile si tu fais du client-side routing)
fastify.setNotFoundHandler((req, reply) => {
  reply.type('text/html').sendFile('index.html');
});

// Exemple d'API
fastify.get('/api/hello', async (req, reply) => {
  return { message: 'Bonjour depuis Fastify !' };
});

// Démarrage du serveur
fastify.listen({ port: 3000, host: '0.0.0.0' }, (err) => {
  if (err) throw err;
});
