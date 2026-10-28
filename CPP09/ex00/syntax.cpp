/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:35:25 by slambert          #+#    #+#             */
/*   Updated: 2026/10/28 12:52:23 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// stoi is c++11 so we use c strtol
int strtol_wrapper(int *res, const std::string &str)
{
	char *end;
	const char *c_str = str.c_str();
	errno = 0;
	*res = std::strtol(c_str, &end, 10);
	if (errno == ERANGE || end == c_str || *end != '\0')
		return FAIL;
	return SUCCESS;
}

int strtod_wrapper(double *res, const std::string &str)
{
	char *end;
	const char *c_str = str.c_str();
	errno = 0;
	*res = std::strtod(c_str, &end);
	if (errno == ERANGE || end == c_str || *end != '\0')
		return FAIL;
	return SUCCESS;
}

static int is_leap_year(int &year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	return 0;
}

static int date_checker (int &year, int &month, int &day)
{
	if (year < 2008 || year > 2035 || month < 1 || month > 12 || day < 1 || day > 31)
		return FAIL;
	int max_days;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		max_days = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		max_days = 30;
	else
	{
		if (is_leap_year(year))
			max_days = 29;
		else
			max_days = 28;		
	}
	if (day > max_days)
		return FAIL;
	return SUCCESS;
}

//"Error: bad input => 2001-42-42"
// 0. char count OK?
// 1. are there 2 dashes?
// 2. first dash must not be in the beginning, last dash not in the end
// 3. extract 3 numbers
// 3a. check if yyyy/mm/dd correct number of chard
// 4. check if numbers make sense
int BitcoinExchange::check_syntax_left(int *year, int *month, int *day, std::string &left) const
{
	// 0.
	if (left.length() != 10)
		return (std::cout << "Error: date syntax. bad input => '" << left << "'" << std::endl, FAIL);
	// 1.
	const int count_dash = std::count(left.begin(), left.end(), '-');
	// std::cout << count_dash << std::endl;
	if (count_dash != 2)
		return (std::cout << "Error: date syntax. bad input => '" << left << "'" << std::endl, FAIL);

	// 2.
	size_t first_dash = left.find('-');
	size_t second_dash = left.find_last_of('-');
	if (first_dash == 0 || second_dash == left.length() - 1)
		return (std::cout << "Error: date syntax. bad input => '" << left << "'" << std::endl, FAIL);
		
	// 3.
	std::string year_str = left.substr(0, first_dash);
	std::string month_str = left.substr(first_dash + 1, second_dash - first_dash - 1);
	std::string day_str = left.substr(second_dash + 1, left.length() - second_dash);
	
	if (year_str.length() != 4 || month_str.length() != 2 || day_str.length() != 2)
		return (std::cout << "Error: date syntax. bad input => '" << left << "'" << std::endl, FAIL);
	if (strtol_wrapper(year, year_str) == FAIL || strtol_wrapper(month, month_str) == FAIL ||
		strtol_wrapper(day, day_str) == FAIL)
		return (std::cout << "Error: date parsing to int. bad input => '" << left << "'" << std::endl, FAIL);

	// 4.
	if (date_checker(*year, *month, *day) == FAIL)
		return (std::cout << "Error: d/m/y to small/big. bad input => '" << left << "'" << std::endl, FAIL);
	return SUCCESS;
}

int BitcoinExchange::check_syntax_right(double *val_right, std::string &right) const
{
	if (strtod_wrapper(val_right, right) == FAIL)
		return (std::cout << "Error: not a valid number." << std::endl, FAIL);
	if (*val_right != *val_right)
		return (std::cout << "Error: nan is not between 0 and 1000." << std::endl, FAIL);
	if (*val_right < 0)
		return (std::cout << "Error: not a positive number." << std::endl, FAIL);
	if (*val_right > 1000)
		return (std::cout << "Error: Too large a number." << std::endl, FAIL);
	return SUCCESS;
}
