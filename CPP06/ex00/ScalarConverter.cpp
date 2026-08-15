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

static float charToFloat(char c)
{
    int temp = (int)c;
    return (float)temp;
}

static void print_int(int num)
{
    if (num >= 32 && num <= 126)
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    else
        std::cout << "char: not printable"  << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " <<  static_cast<float>(num) << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void handleChar(char c)
{
    print_int(static_cast<int>(c));
}

static void handleInt(int i)
{
    print_int(i);
}

static void handleFloatOrDouble(double num_double)
{
    //float num_float = std::stof()
}

static int myAtoi(const char *str)
{
    //check if it is int (or string or smth)
    //over- & underflow check
    return atoi(str);
}

static double myAtof(const char *str)
{
    //check if it is int (or string or smth)
    // check if overflow
    return atof(str);
}

// string to int: std::stoi
// string to float: std::stof
// string to double: std::stod
// but they are not allowed bc they are C++11
//
// allowed is:
// atof: returns double, argument C string
// atoi: returns int, argument C string
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
	int num_int = myAtoi(str.c_str());
	double num_double = myAtof(str.c_str());
	if (num_double - num_int == 0)
	    return handleInt(num_int);
	return handleFloatOrDouble(num_double);
}
