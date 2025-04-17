export const postUserSchema = {
  type: 'object',
  required: ['username', 'email', 'password_hash', 'display_name'],
  properties: {
    username: { type: 'string' },
    email: { type: 'string', format: 'email' },
    password_hash: { type: 'string' },
    display_name: { type: 'string' },
    avatar_url: { type: 'string', nullable: true }
  }
};

