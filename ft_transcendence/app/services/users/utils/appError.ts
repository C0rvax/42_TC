import { FastifyInstance, FastifyRequest, FastifyReply, FastifyError } from 'fastify';

export const ERROR_KEYS = {
    LOGIN_INVALID_CREDENTIALS: 'msg.error.login.invalidCredentials',
    LOGIN_ACCOUNT_BANNED: 'msg.error.login.accountBanned',
    REGISTER_USERNAME_EXISTS: 'msg.error.register.usernameExists',
    REGISTER_EMAIL_EXISTS: 'msg.error.register.emailExists',
    REGISTER_DISPLAYNAME_EXISTS: 'msg.error.register.displayNameExists',
	INVALID_REFRESH_TOKEN: 'msg.error.refreshToken.invalid',
	REFRESH_TOKEN_MISSING: 'msg.error.refreshToken.missing',

    USER_NOT_FOUND: 'msg.error.user.notFound', //
    UNAUTHORIZED: 'msg.error.unauthorized',
    FORBIDDEN: 'msg.error.forbidden',
    DATABASE_ERROR: 'msg.error.databaseError',
    UNKNOWN_ERROR: 'msg.error.unknown'
} as const;

export class AppError extends Error {
    public statusCode: number;
    public messageKey: string;
    public messageParams?: Record<string, any>;

    constructor(messageKey: string, statusCode: number, messageParams?: Record<string, any>) {
        super(messageKey);
        this.statusCode = statusCode;
        this.messageKey = messageKey;
        this.messageParams = messageParams;
        Object.setPrototypeOf(this, AppError.prototype);
    }
}

export class ValidationError extends AppError {
    constructor(messageKey: string, messageParams?: Record<string, any>) {
        super(messageKey, 400, messageParams);
        Object.setPrototypeOf(this, ValidationError.prototype);
    }
}

export class UnauthorizedError extends AppError {
    constructor(messageKey: string, messageParams?: Record<string, any>) {
        super(messageKey, 401, messageParams);
        Object.setPrototypeOf(this, UnauthorizedError.prototype);
    }
}

export class ForbiddenError extends AppError {
    constructor(messageKey: string, messageParams?: Record<string, any>) {
        super(messageKey, 403, messageParams);
        Object.setPrototypeOf(this, ForbiddenError.prototype);
    }
}

export class NotFoundError extends AppError {
    constructor(messageKey: string, messageParams?: Record<string, any>) {
        super(messageKey, 404, messageParams);
        Object.setPrototypeOf(this, NotFoundError.prototype);
    }
}

export class ConflictError extends AppError {
    constructor(messageKey: string, messageParams?: Record<string, any>) {
        super(messageKey, 409, messageParams);
        Object.setPrototypeOf(this, ConflictError.prototype);
    }
}

export function setupErrorHandler(fastify: FastifyInstance): void {
    fastify.setErrorHandler(function (error: FastifyError | AppError | Error, request: FastifyRequest, reply: FastifyReply) {
        request.log.error(error);

        let payload: {
            error: string;
            statusCode: number;
            messageKey: string;
            messageParams?: Record<string, any>;
        };

        if (error instanceof AppError) {
            payload = {
                error: error.message,
                statusCode: error.statusCode,
                messageKey: error.messageKey,
                messageParams: error.messageParams,
            };
        } else {
            const statusCode = (error as FastifyError).statusCode || 500;
            payload = {
                error: error.message || 'An internal server error occurred',
                statusCode: statusCode,
                messageKey: ERROR_KEYS.UNKNOWN_ERROR, // Clé de fallback
            };
        }

        reply.code(payload.statusCode).send(payload);
    });
    fastify.log.info('Internationalized error handler registered');
}
