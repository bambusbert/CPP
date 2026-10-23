/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:16:34 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 12:29:39 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	initialize_prices();
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	initialize_prices();
	loop_input_file(filename);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	rates = other.rates;
	initialize_prices();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		rates.clear();
		rates = other.rates;
	}
	return *this;
}

static int parse_single_data_line(std::string &line, std::map<std::string, double> &rates)
{
	int pos_comma = line.find(',');
	std::string key = line.substr(0, pos_comma);
	std::string value_string = line.substr(pos_comma + 1);
	double value = std::strtod(value_string.c_str(), NULL);
	rates.insert(std::pair<std::string, double>(key, value));
	return 0;
}

int parse_rates(std::ifstream &ifstream, std::map<std::string, double> &rates)
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

// stoi is c++11 so we use c strtol
static int strtol_wrapper(int *res, std::string &str)
{
	char *end;
	const char *c_str = str.c_str();
	errno = 0;
	*res = std::strtol(c_str, &end, 10);
	if (errno == ERANGE || end == c_str || *end != '\0')
		return -1;
	return 0;
}

static int strtod_wrapper(double *res, std::string &str)
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
// 0. char count OK?
// 1. are there 2 dashes?
// 2. first dash must not be in the beginning, last dash not in the end
// 3. extract 3 numbers
// 4. check if numbers make sense
static int check_syntax_left(int *year, int *month, int *day, std::string &left)
{
	// 0.
	if (left.length() != 10)
		return (std::cout << "Error: date syntax. bad input => '" << left << "'" << std::endl, -1);
		
	// 1.
	const int count_dash = std::count(left.begin(), left.end(), '-');
	// std::cout << count_dash << std::endl;
	if (count_dash != 2)
		return (std::cout << "Error: date syntax. bad input => '" << left << "'" << std::endl, -1);

	// 2.
	int first_dash = left.find('-');
	int second_dash = left.find_last_of('-');
	if (first_dash == 0 || second_dash == left.length() - 1)
		return (std::cout << "Error: date syntax. bad input => '" << left << "'" << std::endl, -1);
		
	// 3.
	std::string year_str = left.substr(0, first_dash);
	std::string month_str = left.substr(first_dash + 1, second_dash - first_dash - 1);
	std::string day_str = left.substr(second_dash + 1, left.length() - second_dash);
	if (strtol_wrapper(year, year_str) == -1 || strtol_wrapper(month, month_str) == -1 ||
		strtol_wrapper(day, day_str) == -1)
		return (std::cout << "Error: date parsing to int. bad input => '" << left << "'" << std::endl, -1);

	// 4.
	// i do not check for impossible dates (e.g. 30.2)
	if (*year < 2008 || *year > 2035 || *month < 1 || *month > 12 || *day < 1 || *day > 31)
		return (std::cout << "Error: d/m/y to small/big. bad input => '" << left << "'" << std::endl, -1);
	return 0;
}

static int check_syntax_right(double *val_right, std::string &right)
{
	if (strtod_wrapper(val_right, right) == -1)
		return (std::cout << "Error: not a valid number." << std::endl, -1);
	if (*val_right != *val_right)
		return (std::cout << "Error: nan is not between 0 and 1000." << std::endl, -1);
	if (*val_right < 0)
		return (std::cout << "Error: not a positive number." << std::endl, -1);
	if (*val_right > 1000)
		return (std::cout << "Error: Too large a number." << std::endl, -1);
	return 0;
}

//if key does not exist take the next one below
//lower_bound returns the element that is >= the given key
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

void BitcoinExchange::display_result (const std::string &date, double &amount_traded) const
{
	//1. display date
	std::cout	<< date << " => "
				<< amount_traded << " = "
				<< return_price_for_date(date) * amount_traded 
				<< std::endl;
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
		|| first_pipe == 0				   // nothing before it
		|| first_pipe + 1 >= line.length() // nothing after it
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

int BitcoinExchange::loop_input_file(const std::string &filename) const
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
