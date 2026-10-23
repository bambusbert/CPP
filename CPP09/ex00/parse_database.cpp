/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_database.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:31:48 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 12:53:26 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int parse_single_data_line(std::string &line, std::map<std::string, double> &rates)
{
	int pos_comma = line.find(',');
	std::string key = line.substr(0, pos_comma);
	std::string value_string = line.substr(pos_comma + 1);
	double value = std::strtod(value_string.c_str(), NULL);
	rates.insert(std::pair<std::string, double>(key, value));
	return 0;
}

static int parse_rates(std::ifstream &ifstream, std::map<std::string, double> &rates)
{
	std::string line;

	std::getline(ifstream, line);
	if (line != "date,exchange_rate")
		return (std::cout << "Error: First line of data.csv must be 'date,exchange_rate'" << std::endl,
				-1);
	while (std::getline(ifstream, line))
	{
		if (parse_single_data_line(line, rates) == -1)
			return -1;
	}
	return 0;
}

int BitcoinExchange::initialize_prices()
{
	std::ifstream infile("data.csv", std::ifstream::in);
	if (!infile.is_open())
		return (std::cout << "Error: data.csv could not be opened" << std::endl, 1);
	if (parse_rates(infile, rates) == -1)
		return (std::cout << "Error: parsing error data.csv" << std::endl, 1);
	return 0;
}
