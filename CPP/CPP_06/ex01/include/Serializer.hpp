/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:08:09 by aduvilla          #+#    #+#             */
/*   Updated: 2025/02/05 20:40:59 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	public:
	static uintptr_t	serialize(Data * ptr);
	static Data*		deserialize(uintptr_t raw);

	private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& src);
	Serializer& operator=(const Serializer& rhs);
};

#endif
