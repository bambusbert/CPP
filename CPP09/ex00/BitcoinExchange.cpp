/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:16:34 by slambert          #+#    #+#             */
/*   Updated: 2026/10/26 15:17:28 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _input_file("")
{
	//initialize_rates();
}

BitcoinExchange::BitcoinExchange(const std::string &filename): _input_file(filename)
{
	if (initialize_rates() == -1)
		_input_file = "";
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : rates(other.rates), _input_file(other._input_file)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_input_file = other._input_file;
		rates.clear();
		rates = other.rates;
	}
	return *this;
}

// if key does not exist take the next one below
// lower_bound returns the element that is >= the given key
double BitcoinExchange::return_price_for_date(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it;
	it = rates.lower_bound(date);
	if (it != rates.end() && it->first == date)
		return it->second;
	if (it == rates.begin())
		return -1;
	return (--it)->second;
}

void BitcoinExchange::display_result(const std::string &date, double &amount_traded) const
{
	std::cout << date << " => " << amount_traded << " = "
			  << return_price_for_date(date) * amount_traded << std::endl;
}

// Rules:
// 1.	there has to be 1 pipe, must not be at the beginning nor the end
// 2.	split in left and right
// 3.	check left and right
void BitcoinExchange::parse_single_value_line(std::string &line) const
{
	// 1.
	std::string::size_type first_pipe = line.find('|');
	if (first_pipe == std::string::npos	   // no pipe
		|| first_pipe != line.rfind('|')   // more than one pipe
		|| first_pipe == 0				   // nothing before pipe
		|| first_pipe + 1 >= line.length() // nothing after pipe
		|| line[first_pipe - 1] != ' '	   // no space before
		|| line[first_pipe + 1] != ' ')	   // no space after
	{
		std::cout << "Error: pipe(s). bad input => '" << line << "'" << std::endl;
		return;
	}
	// 2.
	std::string left = line.substr(0, first_pipe - 1);
	std::string right = line.substr(first_pipe + 2, line.length());
	double val_right;
	int year, month, day;
	if (check_syntax_right(&val_right, right) == -1 ||
		check_syntax_left(&year, &month, &day, left) == -1)
		return;
	display_result(left, val_right);
}

void BitcoinExchange::loop_input_file() const
{
	if (_input_file == "")
	{
		//std::cout << "Error. btc exchange does not have an input file" << std::endl;
		return ;
	}
	std::ifstream infile(_input_file.c_str(), std::ifstream::in);
	if (!infile.is_open())
	{
		std::cout << "Error. input file could not be opened" << std::endl;
		return;
	}

	std::string line;
	std::getline(infile, line);
	if (line != "date | value")
	{
		std::cout << "Error. First line of input file must be 'date | value'" << std::endl;
		return;
	}
	while (std::getline(infile, line))
		parse_single_value_line(line);
}
