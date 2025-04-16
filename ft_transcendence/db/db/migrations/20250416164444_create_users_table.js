/**
 * @param { import("knex").Knex } knex
 * @returns { Promise<void> }
 */
exports.up = function(knex) {
  return knex.schema.createTable('users', (table) => {
    table.increments('id').primary();
    table.string('username').unique().notNullable();
    table.string('email').unique().notNullable();
    table.string('password_hash').notNullable();
    table.string('display_name').unique().notNullable();
    table.string('avatar_url').nullable();
    table.integer('wins').defaultTo(0).notNullable();
    table.integer('losses').defaultTo(0).notNullable();
    table.string('status').defaultTo('offline').notNullable(); // 'online', 'offline', 'in-game'
    table.timestamps(true, true); // Adds created_at and updated_at
  });
};

/**
 * @param { import("knex").Knex } knex
 * @returns { Promise<void> }
 */
exports.down = function(knex) {
  return knex.schema.dropTable('users');
};
