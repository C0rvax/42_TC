/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduvilla <aduvilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:47:07 by aduvilla          #+#    #+#             */
/*   Updated: 2025/01/28 23:25:33 by aduvilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# define DATACSV "data.csv"

class	BitcoinExchange
{
	public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange &operator=(BitcoinExchange const & rhs);
	~BitcoinExchange(void);
	void	HowRichIAm(char* input);

	private:
	std::map<int, double>		m_map;
	int							m_dateMin;
	int							m_dateMax;

	void	mapDataCsv();
	void	setMap(std::string& date, std::string& value);
	int		getIntDate(std::string& date);
	bool	isValidDate(const std::string& date);
};

void	decrementDay(int& date);
double	stodouble(const std::string& str);

#endif
