/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:16:34 by slambert          #+#    #+#             */
/*   Updated: 2026/10/22 21:24:36 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : init_successful(true)
{
	// initialize amount not called
	if (initialize_prices() == -1)
		init_successful = false;
}

BitcoinExchange::BitcoinExchange(const std::string &filename) : init_successful(true)
{
	if (initialize_prices() == -1 || loop_input_file(filename) == -1)
		init_successful = false;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : init_successful(true)
{
	if (initialize_prices() == -1)
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
		return (std::cout << "First line of data.csv must be 'date,exchange_rate'" << std::endl,
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
		return (std::cout << "data.csv could not be opened" << std::endl, 1);
	if (parse_rates(infile, rates) == -1)
		return (std::cout << "parsing error data.csv" << std::endl, 1);
	return 0;
}

// stoi is c++11 so we use c strtol
int strtol_wrapper(int *res, std::string &str)
{
	char *end;
	const char *c_str = str.c_str();
	errno = 0;
	*res = std::strtol(c_str, &end, 10);
	if (errno == ERANGE || end == c_str || *end != '\0')
		return -1;
	return 0;
}

int strtod_wrapper(double *res, std::string &str)
{
	char *end;
	const char *c_str = str.c_str();
	errno = 0;
	*res = std::strtod(c_str, &end);
	if (errno == ERANGE || end == c_str || *end != '\0')
		return -1;
	return 0;
}

//"Error: bad input => 2001-42-42"
// 1. are there 2 dashes?
// 2. first dash must not be in the beginning, last dash not in the end
// 3. extract 3 numbers
// 4. check if numbers make sense
int check_syntax_left(int *year, int *month, int *day, std::string &left)
{
	// 1.
	const int count_dash = std::count(left.begin(), left.end(), '-');
	// std::cout << count_dash << std::endl;
	if (count_dash != 2)
		return (std::cout << "Error: bad input => " << left << std::endl, -1);

	// 2.
	int first_dash = left.find('-');
	int second_dash = left.find_last_of('-');
	if (first_dash == 0 || second_dash == left.length() - 1)
		return (std::cout << "Error: bad input => " << left << std::endl, -1);
	// 3.
	std::string year_str = left.substr(0, first_dash);
	std::string month_str = left.substr(first_dash + 1, second_dash - first_dash - 1);
	std::string day_str = left.substr(second_dash + 1, left.length() - second_dash);
	// std::cout << "Year: '" << year_str << "', Month: '" << month_str << "', Day: '" << day_str
	// 		  << "'" << std::endl;

	// int year, month, day;
	if (strtol_wrapper(year, year_str) == -1 || strtol_wrapper(month, month_str) == -1 ||
		strtol_wrapper(day, day_str) == -1)
		return (std::cout << "Error: bad input => " << left << std::endl, -1);
	// std::cout << "Year: " << *year << ", Month: " << *month << ", Day: " << *day << std::endl
	// 		  << std::endl;

	// 4.
	// i do not check for impossible dates (e.g. 30.2)
	if (*year < 2008 || *year > 2035 || *month < 1 || *month > 12 || *day < 1 || *day > 31)
		return (std::cout << "Error: bad input => " << left << std::endl, -1);
	return 0;
}

// TODO das ist long es sollte float sein
int check_syntax_right(double *val_right, std::string &right)
{
	if (strtod_wrapper(val_right, right) == -1)
		return -1;
	if (*val_right < 0)
		return (std::cout << "Error: not a positive number." << std::endl, -1);
	if (*val_right > 1000)
		return (std::cout << "Error: Too large a number." << std::endl, -1);
	return 0;
}

void display_result (int &year, int &month, int &day, double &val)
{
	//1. display date
	std::cout	<< std::setfill('0')
				<< std::setw(4) << year << "-"
				<< std::setw(2) << month << "-"
				<< std::setw(2) << day
				<< std::setfill(' ')
				<< " => " << val << " = " << "..." << std::endl;
	//2. display val
	//3. display val * price
	//(2011-01-03 => 1.2 = 0.36)
}

// Rules:
// 1.	there has to be 1 pipe, must not be at the beginning nor the end
// 2.	split in left and right
// 3.	check left and right
// check if stuff right of pipe is a valid double
// if parsing ok: print output
//TODO only pass left string and look database for that key.
//(if key not there find closest one - in the past)
void parse_single_value_line(std::string &line)
{
	// 1.
	//std::cout << "Line: " << line << std::endl;
	std::string::size_type first_pipe = line.find('|');
	if (first_pipe == std::string::npos	   // no pipe
		|| first_pipe != line.rfind('|')   // more than one pipe
		|| first_pipe == 0				   // nothing before it
		|| first_pipe + 1 >= line.length() // nothing after it
		|| line[first_pipe - 1] != ' '	   // no space before
		|| line[first_pipe + 1] != ' ')	   // no space after
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	// 2.
	std::string left = line.substr(0, first_pipe - 1);
	std::string right = line.substr(first_pipe + 2, line.length());
	// std::cout << "Line: " << line << std::endl << "Left: '" << left << "', Right: '" << right <<
	// "'" << std::endl << std::endl;
	double val_right;
	int year, month, day;
	if (check_syntax_right(&val_right, right) == -1 ||
		check_syntax_left(&year, &month, &day, left) == -1)
		return;
	display_result(year, month, day, val_right);
}

int BitcoinExchange::loop_input_file(const std::string &filename)
{
	std::ifstream infile(filename.c_str(), std::ifstream::in);
	if (!infile.is_open())
		return (std::cout << "input file could not be opened" << std::endl, 1);

	std::string line;
	std::getline(infile, line);
	if (line != "date | value")
		return (std::cout << "First line of input file must be 'date | value'" << std::endl, -1);
	while (std::getline(infile, line))
		parse_single_value_line(line);
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
