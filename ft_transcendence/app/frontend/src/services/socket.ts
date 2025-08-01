import { Socket } from "socket.io-client";

const socket: typeof Socket = io({
	path: "/socket-client/",
	autoConnect: false,
});

export const tournamentSocket: typeof Socket = io({
    path: "/socket-tournament/",
    autoConnect: false,
});

export default socket;
