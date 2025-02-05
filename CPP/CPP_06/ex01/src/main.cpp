/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:14:34 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 20:21:15 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data	robert = {.level = 9, .name = "robert"};
	Data*		deserializedRobert = Serializer::deserialize(Serializer::serialize(&robert));

	std::cout << (deserializedRobert == &robert ? "struct are the same" : "struct are differents") << std::endl;
	std::cout << "OG name: " << robert.name << " / level: " << robert.level << std::endl;
	std::cout << "Deserialized name: " << deserializedRobert->name << " / level: " << deserializedRobert->level << std::endl;
	return 0;
}
