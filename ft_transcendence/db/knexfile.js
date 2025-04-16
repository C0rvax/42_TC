// knexfile.js
require('dotenv').config(); // Load .env variables

module.exports = {
  development: {
    client: 'sqlite3',
    connection: {
      filename: process.env.DB_FILENAME || './mydb.sqlite' // Store DB path in .env
    },
    useNullAsDefault: true, // Recommended for SQLite
    migrations: {
      directory: './db/migrations'
    },
    seeds: {
      directory: './db/seeds'
    }
  },
  // Add production config if needed
};
