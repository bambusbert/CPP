/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:16:34 by slambert          #+#    #+#             */
/*   Updated: 2026/10/21 19:55:25 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): init_successful(true)
{
    if (initialize() == -1)
        init_successful = false;   
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): init_successful(true)
{
    if (initialize() == -1)
        init_successful = false;  
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
	}
	return *this;
}

// returns -1 on error
// 0 if OK
// eigentlich brauche ich gar kein error handling, weil data.csv ist vorgegeben
static int parse_single_line(std::string &line, std::map<std::string, double> &rates)
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
		return -1;
	while (std::getline(ifstream, line))
	{
		if (parse_single_line(line, rates) == -1)
			return -1;
	}
	return 0;
}

int BitcoinExchange::initialize()
{
	std::ifstream infile("data.csv", std::ifstream::in);
	if (!infile.is_open())
	{
		std::cout << "file could not be opened" << std::endl;
		return 1;
	}
	if (parse_rates(infile, rates) == -1)
	{
		std::cout << "parsing error data.csv" << std::endl;
		return 1;
	}
	return 0;
}

void BitcoinExchange::print_daily_prices()
{
    for (std::map<std::string, double>::iterator i = rates.begin(); i != rates.end(); ++i)
        std::cout << i->first << ", " << i->second << std::endl;
}

bool BitcoinExchange::get_init_successful()
{
    return init_successful;
}
