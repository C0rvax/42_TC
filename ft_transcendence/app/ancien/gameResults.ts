import { cleanupSocket } from "../services/initOnlineGame.js";
import { navigateTo } from "../services/router.js";
import socket from '../services/socket.js';
import { t } from '../services/i18nService.js';
import { TournamentData } from '../shared/schemas/matchesSchemas.js';

export function showGameResult(player1: string, player2: string, score1: number, score2: number, url1: string, url2: string, destinationUrl: string, destinationText: string) {

	const modal = document.createElement('div');
	modal.className = 'fixed inset-0 z-50 flex items-center justify-center bg-black/60 backdrop-blur-md';

	const content = document.createElement('div');
	content.className = 'bg-gray-900/70 backdrop-blur-lg border border-gray-400/30 rounded-2xl shadow-2xl p-6 sm:p-8 w-[90%] max-w-lg text-center';

	// Titre
	const title = document.createElement('h2');
	title.className = 'text-3xl font-bold text-white mb-6 border-b border-gray-500/30 pb-4';
	title.textContent = t('game.result.finished');

	// Container des joueurs
	const playersContainer = document.createElement('div');
	playersContainer.className = 'flex justify-around items-center gap-4 my-6';

	// Joueur 1
	const player1Container = document.createElement('div');
	player1Container.className = 'flex flex-col items-center flex-1 transition-all duration-300';

	const img1 = document.createElement('img');
	img1.src = url1;
	img1.className = 'w-24 h-24 object-cover rounded-full mb-3 border-4 border-blue-500 shadow-lg';

	const name1 = document.createElement('p');
	name1.className = 'font-semibold text-xl text-gray-200';
	name1.textContent = player1;

	const scoreText1 = document.createElement('p');
	scoreText1.className = 'text-4xl font-bold text-blue-400';
	scoreText1.textContent = String(score1);

	player1Container.appendChild(img1);
	player1Container.appendChild(name1);
	player1Container.appendChild(scoreText1);

	// "vs" texte
	const vsText = document.createElement('span');
	vsText.className = 'text-4xl font-bold text-gray-400 mx-4';
	vsText.textContent = t('game.vs');

	// Joueur 2
	const player2Container = document.createElement('div');
	player2Container.className = 'flex flex-col items-center flex-1 transition-all duration-300';

	const img2 = document.createElement('img');
	img2.src = url2;
	img2.className = 'w-24 h-24 object-cover rounded-full mb-3 border-4 border-red-500 shadow-lg';

	const name2 = document.createElement('p');
	name2.className = 'font-semibold text-xl text-gray-200';
	name2.textContent = player2;

	const scoreText2 = document.createElement('p');
	scoreText2.className = 'text-4xl font-bold text-red-500';
	scoreText2.textContent = String(score2);

	player2Container.appendChild(img2);
	player2Container.appendChild(name2);
	player2Container.appendChild(scoreText2);

	const rawData = sessionStorage.getItem('tournamentData');
	if (rawData) {
		let data: TournamentData;
		try {
			data = JSON.parse(rawData);
			if (!data.results) {
				data.results = new Array(data.pairs.length * 2).fill(null);
			}
		} catch (err) {
			console.log("couldnt parse data")
			return;
		}
		let i = 0
		while (data.results[i] != null)
			i++
		if (score1 > score2) {
			data.results[i] = 0;
		} else if (score2 > score1) {
			data.results[i] = 1;
		}
		console.log(data.results[i])
		sessionStorage.setItem('tournamentData', JSON.stringify(data))
	}

	if (score1 > score2) {
		player1Container.classList.add('opacity-100', 'scale-105');
		player2Container.classList.add('opacity-60', 'scale-95');
	} else if (score2 > score1) {
		player2Container.classList.add('opacity-100', 'scale-105');
		player1Container.classList.add('opacity-60', 'scale-95');
	}

	const closeButton = document.createElement('button');
	closeButton.id = 'close-modal';
	closeButton.className = 'mt-8 px-8 py-3 bg-blue-600 hover:bg-blue-700 text-white font-semibold rounded-lg shadow-lg border border-blue-500/50 transition-all duration-200 hover:scale-105';
	closeButton.textContent = destinationText;

	playersContainer.appendChild(player1Container);
	playersContainer.appendChild(vsText);
	playersContainer.appendChild(player2Container);

	content.appendChild(title);
	content.appendChild(playersContainer);
	content.appendChild(closeButton);
	modal.appendChild(content);
	document.body.appendChild(modal);

	closeButton.addEventListener('click', () => {
		modal.remove();

		const onlineTournamentId = sessionStorage.getItem('onlineTournamentId');
		if (!onlineTournamentId) {
			cleanupSocket(socket);
		}

		const gameMode = sessionStorage.getItem('gameMode');

		if (gameMode === 'tournament') {
			sessionStorage.removeItem('matchId');
			sessionStorage.removeItem('player1');
			sessionStorage.removeItem('player2');
		} else {
			sessionStorage.clear();
		}
		navigateTo(destinationUrl);
	});
}
