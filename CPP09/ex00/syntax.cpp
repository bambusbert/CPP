/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:35:25 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 12:53:18 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
// 0. char count OK?
// 1. are there 2 dashes?
// 2. first dash must not be in the beginning, last dash not in the end
// 3. extract 3 numbers
// 4. check if numbers make sense
int BitcoinExchange::check_syntax_left(int *year, int *month, int *day, std::string &left) const
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
	size_t first_dash = left.find('-');
	size_t second_dash = left.find_last_of('-');
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

int BitcoinExchange::check_syntax_right(double *val_right, std::string &right) const
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
