exports.up = function(knex) {
  return knex.schema.createTable('friendships', (table) => {
    table.increments('id').primary();
    table.integer('user_id1').unsigned().notNullable().references('id').inTable('users').onDelete('CASCADE');
    table.integer('user_id2').unsigned().notNullable().references('id').inTable('users').onDelete('CASCADE');
    table.string('status').notNullable(); // 'pending', 'accepted', 'blocked'
    table.timestamps(true, true);
    table.unique(['user_id1', 'user_id2']); // Prevent duplicate pairs
    table.check('user_id1 < user_id2'); // Convention to avoid duplicates like (1,2) and (2,1)
  });
};
exports.down = function(knex) {
  return knex.schema.dropTable('friendships');
};
