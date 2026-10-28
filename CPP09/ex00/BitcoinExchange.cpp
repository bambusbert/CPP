/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:16:34 by slambert          #+#    #+#             */
/*   Updated: 2026/10/28 12:47:06 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
// TODO Dates before the first rate print garbage
BitcoinExchange::BitcoinExchange() : _input_file("")
{
	// that's nonsensical but subject requires it
	// initialize_rates();
	_init_successful = false;
}

BitcoinExchange::BitcoinExchange(const std::string &filename) : _input_file(filename)
{
	if (initialize_rates() == FAIL)
		_init_successful = false;
	else
		_init_successful = true;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates), _input_file(other._input_file), _init_successful(other._init_successful)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_input_file = other._input_file;
		_rates.clear();
		_rates = other._rates;
		_init_successful = other._init_successful;
	}
	return *this;
}

// if key does not exist take the next one below
// lower_bound returns the element that is >= the given key
double BitcoinExchange::return_price_for_date(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it;
	it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date)
		return it->second;
	if (it == _rates.begin())
		return FAIL;
	return (--it)->second;
}

void BitcoinExchange::display_result(const std::string &date, double &amount_traded) const
{
	double price = return_price_for_date(date);
	if (price == FAIL)
	{
		std::cout << "Error: no regarding price in database. (valid date but no match)" << std::endl;
		return;
	}
	std::cout << date << " => " << amount_traded << " = "
			  << price * amount_traded << std::endl;
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
	if (_init_successful == false)
	{
		std::cout << "Error. loop can't be executed because initialization failed" << std::endl;
		return;
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
