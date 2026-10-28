/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_rates.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:31:48 by slambert          #+#    #+#             */
/*   Updated: 2026/10/28 14:12:06 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int parse_single_rate_line(std::string &line, std::map<std::string, double> &rates)
{
	int pos_comma = line.find(',');
	std::string key = line.substr(0, pos_comma);
	std::string value_string = line.substr(pos_comma + 1);
	double value;
	if (strtod_wrapper(&value, value_string) == FAIL)
		return FAIL;
	rates.insert(std::pair<std::string, double>(key, value));
	return SUCCESS;
}

static int parse_rates(std::ifstream &ifstream, std::map<std::string, double> &rates)
{
	std::string line;

	std::getline(ifstream, line);
	if (line != "date,exchange_rate")
		return (std::cout << "Error. First line of data.csv must be 'date,exchange_rate'" << std::endl,
				FAIL);
	while (std::getline(ifstream, line))
	{
		if (parse_single_rate_line(line, rates) == FAIL)
			return FAIL;
	}
	return SUCCESS;
}

int BitcoinExchange::initialize_rates()
{
	std::ifstream infile("data.csv", std::ifstream::in);
	if (!infile.is_open())
		return (std::cout << "Error. data.csv could not be opened" << std::endl, FAIL);
	if (parse_rates(infile, _rates) == FAIL)
		return (std::cout << "Error. parsing error data.csv" << std::endl, FAIL);
	return SUCCESS;
}
