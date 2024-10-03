/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedpp.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:33:13 by aduvilla          #+#    #+#             */
/*   Updated: 2024/10/03 18:50:49 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDPP_HPP
# define SEDPP_HPP

# include <string>

# define FORM " try ./Sedpp [filename] [s1] [s2]"
# define ERR_FILE ": cannot open file"

class	Sedpp
{
	public:
		Sedpp(std::string filename, std::string s1, std::string s2);
		~Sedpp();
		int	sedReplace();
	private:
		std::string	m_replace(std::string buff);
		std::string m_filename;
		std::string	m_s1;
		std::string	m_s2;
};
#endif
