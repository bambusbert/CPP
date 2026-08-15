/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:55 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 14:05:48 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <cstdlib>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {

    }
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static void printChar(long num)
{
    if (num >= 32 && num <= 126)
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    else
        std::cout << "char: not printable"  << std::endl;
}

static void printInt(long num)
{
    if (num > INT_MAX || num < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << num << std::endl;
}

static void printFloat(float num)
{
    std::cout << "float: " <<  static_cast<float>(num) << "f" << std::endl;
}

static void printDouble(double num)
{
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void print_char_stuff(long num)
{
    printChar(num);
    printInt(num);
    printFloat(static_cast<float>(num));
    printDouble(static_cast<double>(num));
}

static void handleInt(std::string str)
{
    //strol
    char *endptr;

    long num = strtol(str.c_str(), &endptr, 10);
    printChar(num);
    printInt(num);
    printFloat(static_cast<float>(num));
    printDouble(static_cast<double>(num));
}

static void handleChar(char c)
{
    print_char_stuff(static_cast<long>(c));
}

static bool isFloatOrDouble(std::string str)
{
    int countCommas = 0;
    int countF = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == 'f'))
            return false;
        if (str[i] == '.')
            countCommas++;
        if (str[i] == 'f')
            countF++;
    }
    if (countCommas == 1 && countF == 0)
    {
        std::cout << "double" << std::endl;
        return true;
    }
    if (countCommas > 1 || countF > 1 || (countF == 1 && str[str.length() - 1] != 'f'))
        return false;
    if (countCommas == 0 && countF == 0)
        return false;
    std::cout << "float" << std::endl;
    return true;
}

void ScalarConverter::convert(std::string str)
{
	// if length is 1 and ascii printable: char (exclude 0-9)
	//  else if valid_float || valid_double || valid_int
	//char
	if (str.length() == 1 && static_cast<int>(str[0]) >= 32 && static_cast<int>(str[0]) <= 126)
	{
		if (!(str[0] >= '0' && str[0] <= '9'))
			return handleChar(str[0]);
	}
	if (!isFloatOrDouble(str))
	{
	    handleInt(str);
		exit (0);
	}
	//     handleFloat(str);


	//strol
	// strtod

}
