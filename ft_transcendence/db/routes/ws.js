// routes/ws.js

// Store active connections (In-memory is simple, consider Redis for scaling)
const connections = new Map(); // Map<userId, WebSocketConnection>

async function websocketRoutes(fastify, options) {
    const knex = fastify.knex;

    fastify.get('/', { websocket: true }, async (connection /* SocketStream */, req /* FastifyRequest */) => {
        let userId = null;

        // 1. Authenticate WebSocket connection (e.g., using a token in query param or first message)
        try {
            // Example: Token in query string ?token=...
            const token = req.query.token;
            if (!token) throw new Error('No token provided');

            const decoded = await fastify.jwt.verify(token); // Verify the token passed during connection
            userId = decoded.id;

             // Check if user exists and is valid
             const user = await knex('users').where({ id: userId }).first();
             if (!user) throw new Error('Invalid user');

            // Check for existing connection for this user (optional: disconnect old one?)
            if (connections.has(userId)) {
                console.warn(`User ${userId} already connected. Closing previous connection.`);
                connections.get(userId).socket.close(1001, 'New connection established');
            }

            // Store the connection
            connections.set(userId, connection);
            req.log.info(`WebSocket connected for user ${userId}`);

            // Update user status in DB to 'online'
            await knex('users').where({ id: userId }).update({ status: 'online', updated_at: knex.fn.now() });
            // TODO: Notify friends user came online

        } catch (err) {
            req.log.error(`WebSocket authentication failed: ${err.message}`);
            connection.socket.close(1008, 'Authentication failed'); // Close with policy violation code
            return; // Stop processing if auth fails
        }


        // 2. Handle messages from the client
        connection.socket.on('message', message => {
            try {
              // Handle incoming messages (chat, game invites, etc.)
              req.log.info(`Received message from user ${userId}: ${message}`);
              // Example: Broadcast message (you'll need more logic for specific actions)
              // connections.forEach(conn => conn.socket.send(`User ${userId} says: ${message}`));
            } catch (err) {
               req.log.error(`Error processing message from user ${userId}: ${err}`);
            }
        });

        // 3. Handle disconnection
        connection.socket.on('close', async (code, reason) => {
            req.log.info(`WebSocket disconnected for user ${userId}. Code: ${code}, Reason: ${reason}`);
            if (userId && connections.get(userId) === connection) { // Ensure we remove the correct connection
                connections.delete(userId);
                // Update user status in DB to 'offline' only if no other connections exist for this user
                 if (!connections.has(userId)) {
                    await knex('users').where({ id: userId }).update({ status: 'offline', updated_at: knex.fn.now() });
                    // TODO: Notify friends user went offline
                }
            }
        });

         // 4. Handle errors
         connection.socket.on('error', error => {
            req.log.error(`WebSocket error for user ${userId}: ${error}`);
             // Consider closing the connection on certain errors
        });
    });

    // Helper function to send message to a specific user (if needed)
    fastify.decorate('sendWsMessage', (targetUserId, message) => {
        const connection = connections.get(targetUserId);
        if (connection) {
            connection.socket.send(JSON.stringify(message)); // Always send JSON is a good practice
            return true;
        }
        return false;
    });

    // Helper function to broadcast (if needed)
     fastify.decorate('broadcastWsMessage', (message, excludeUserId = null) => {
        const stringifiedMessage = JSON.stringify(message);
        connections.forEach((conn, userId) => {
            if (userId !== excludeUserId) {
                conn.socket.send(stringifiedMessage);
            }
        });
    });
}

module.exports = websocketRoutes;
