/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:01:06 by aduvilla          #+#    #+#             */
/*   Updated: 2024/11/05 18:13:28 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);

	private:
		std::string	name;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
