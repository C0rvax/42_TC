import { getUserByUsername, createUser, getAllUsersFromDb, insertUserIntoDb } from '../models/userModel.js';
//import { hashPassword, comparePassword } from '../utils/pswdUtils.js';
//import { generateJWT } from '../utils/jwtUtils.js';

export async function registerUser(username, email, password, display_name, reply) {
  const existingUser = await getUserByUsername(username);
  if (existingUser) {
    throw new Error('Username already exists');
  }

  const hashedPassword = await hashPassword(password);
  const user = await createUser({ username, email, password_hash: hashedPassword, display_name });

  return user;
}

export async function loginUser({ username, password }) {
  const user = await getUserByUsername(username);
  if (!user || !(await comparePassword(password, user.password_hash))) {
    throw new Error('Invalid credentials');
  }

  const token = generateJWT({ id: user.id, username: user.username });
  return token;
}


export async function getAllUsers() {
  return await getAllUsersFromDb();
}

export async function createUserAccount(userData) {
  return await insertUserIntoDb(userData);
}
