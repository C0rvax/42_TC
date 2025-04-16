import Fastify from 'fastify';
import sqlite3 from 'sqlite3';
import { open } from 'sqlite';
import fs from 'fs';
import path from 'path';

const fastify = Fastify({ logger: true });

let db;

fastify.get('/api/users', async () => {
  const users = await db.all('SELECT * FROM users');
  return users;
});

const start = async () => {
  // Ouverture de la base de données
  db = await open({
    filename: './db/database.sqlite',
    driver: sqlite3.Database
  });

  // Utilisation de import.meta.url pour obtenir le répertoire courant
  const initSQLPath = new URL('./db/init.sql', import.meta.url).pathname;

  // Vérification et exécution de l'init.sql
  if (fs.existsSync(initSQLPath)) {
    const sql = fs.readFileSync(initSQLPath, 'utf-8');
    await db.exec(sql);  // Exécution du script d'initialisation
    console.log('Base de données initialisée avec succès');
  } else {
    console.error('Le fichier init.sql est introuvable');
    console.log('Chemin absolu vers init.sql :', initSQLPath);

  }

  await fastify.listen({ port: 3000, host: '0.0.0.0' });
};

start();
