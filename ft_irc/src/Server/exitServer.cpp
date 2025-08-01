/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:01:56 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/27 11:08:16 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Client.hpp"
#include <unistd.h>
#include "Channel.hpp"
#include "utils.hpp"

/**
 * @brief Destructor for the Server class.
 */
Server::~Server()
{
	CloseFds();
	for (size_t i = 0; i < m_vChannels.size(); i++)
		if(m_vChannels[i])
			delete m_vChannels[i];
	for (size_t i = 0; i < m_vClients.size(); i++)
		if(m_vClients[i])
			delete m_vClients[i];
	m_vClients.clear();
	m_vChannels.clear();
	m_vFds.clear();
	sendLog("closing");
	sendLog("\n============================================\n");
	m_logFd.close();
}

/**
 * @brief Closes all file descriptors.
 */
void	Server::CloseFds()
{
	for(size_t i = 0; i < m_vClients.size(); i++){ //-> close all the clients
		sendLog("Client <" + itoa(m_vClients[i]->getFD()) + "> Disconnected");
		close(m_vClients[i]->getFD());
	}
	if (m_serverSocketFd != -1){ //-> close the server socket
		sendLog("Server <" + itoa(m_serverSocketFd) + "> Disconnected");
		close(m_serverSocketFd);
	}
}

/**
 * @brief Clears a client from the server.
 * 
 * @param client The client to clear.
 */
void Server::ClearClient(Client &client)
{
	for (size_t i = 0; i < m_vFds.size(); i++)
	{
		if (m_vFds[i].fd == client.getFD())
		{
			close (m_vFds[i].fd);
			m_vFds.erase(m_vFds.begin() + i);
			break;
		}
	}
	for (size_t i = 0; i < m_vClients.size(); i++)
	{
		if (m_vClients[i] == &client)
		{
			m_vClients[i]->cleanChannels();
			delete m_vClients[i];
			m_vClients.erase(m_vClients.begin() + i);
			break;
		}
	}
}

/**
 * @brief Deletes a channel from the server.
 * 
 * @param channel The channel to delete.
 */
void 	Server::deleteChannel(Channel &channel)
{
	for (size_t i = 0; i < m_vChannels.size(); i++) {
		if (m_vChannels[i] == &channel)
		{
			m_vChannels[i]->cleanClient();
			delete m_vChannels[i];
			m_vChannels.erase(m_vChannels.begin() + i);
			break;
		}
	}
}
