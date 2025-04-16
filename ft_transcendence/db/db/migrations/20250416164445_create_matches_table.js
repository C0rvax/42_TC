exports.up = function(knex) {
  return knex.schema.createTable('matches', (table) => {
    table.increments('id').primary();
    table.integer('player1_id').unsigned().notNullable().references('id').inTable('users').onDelete('CASCADE');
    table.integer('player2_id').unsigned().notNullable().references('id').inTable('users').onDelete('CASCADE');
    table.integer('player1_score').notNullable();
    table.integer('player2_score').notNullable();
    table.integer('winner_id').unsigned().nullable().references('id').inTable('users').onDelete('SET NULL');
    table.string('game_type').defaultTo('pong').notNullable();
    // tournament_id can be added later if needed
    table.timestamp('match_date').defaultTo(knex.fn.now());
  });
};
exports.down = function(knex) {
    return knex.schema.dropTable('matches');
};
