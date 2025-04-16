// plugins/db.js
const fp = require('fastify-plugin');
const knex = require('knex');

async function dbConnector(fastify, options) {
  try {
    const knexConfig = require('../knexfile')[process.env.NODE_ENV || 'development'];
    const knexInstance = knex(knexConfig);

    // Test connection (optional but recommended)
    await knexInstance.raw('SELECT 1');

    fastify.decorate('knex', knexInstance);
    fastify.log.info('Knex connection successful');

    fastify.addHook('onClose', (instance, done) => {
      instance.knex.destroy(done);
    });
  } catch (err) {
    fastify.log.error('Knex connection error:', err);
    process.exit(1); // Exit if DB connection fails
  }
}

module.exports = fp(dbConnector);
