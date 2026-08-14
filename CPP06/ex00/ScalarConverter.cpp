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
#include <string>

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

static void print1(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " <<  static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void handleChar(char c)
{
    print1(c);
}

static void handleInt(int i)
{
    print1(static_cast<char>(i));
}

static void handleFloatOrDouble(double num)
{

}

// string to int: std::stoi
// string to float: std::stof
// string to double: std::stod
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
	//int
	int num_int = std::stoi(str);
	double num_double = std::stod(str);
	if (num_double - num_int == 0)
	    return handleInt(num_int);
	return handleFloatOrDouble(num_double);
}
