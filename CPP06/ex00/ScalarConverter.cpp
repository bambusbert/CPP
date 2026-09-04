/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:55 by slambert          #+#    #+#             */
/*   Updated: 2026/09/04 12:06:54 by slambert         ###   ########.fr       */
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

// static float charToFloat(char c)
// {
//     int temp = (int)c;
//     return (float)temp;
// }

static void print_char(int num)
{
    if (num >= 32 && num <= 126)
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    else
        std::cout << "char: impossible"  << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " <<  static_cast<float>(num) << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void handleChar(char c)
{
    print_char(static_cast<int>(c));
}

// static void handleInt(int i)
// {
//     std::cout << "the number is INT" << std::endl;
//     print_char(i);
// }

// static void handleFloatOrDouble(double num_double)
// {
//     //float num_float = std::stof()
//     std::cout << "the number is FLOAT OR DOUBLE" << std::endl;
// }

static int myAtoi(const char *str, bool* impossible)
{
    int i = 0;
    long ret = 0;
    bool minus = 0;
    
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if (str[i] == '-')
    {
        minus = 1;
        i++;
    }
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        ret *= 10;
        ret += str[i] - 48;
        if (ret == (long)INT_MAX + 1 && minus)
            return INT_MIN;
        if (ret > INT_MAX)
            return (*impossible = true, -1);
        i++;
    }
    if (minus)
        ret *= 1;
    return ret;
}

static double myAtof(const char *str)
{
    double ret = atof(str);
    //std::cout << "atof:" << ret << std::endl;
    return ret;
}

static void print_nums(int num_int, float num_float, double num_double)
{
    std::cout << "char: impossible"  << std::endl;
	std::cout << "int: " << num_int << std::endl;
	std::cout << "float: " <<  num_float << std::endl;
	std::cout << "double: " << num_double << std::endl;
}

static float doubleToFloat(double num_double)
{
    //float ret;
    return static_cast<float>(num_double);
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
    bool int_imp = false;
	int num_int = myAtoi(str.c_str(), &int_imp);
    //std::cout << "my atoi - INT:" << num_int << std::endl;
	double num_double = myAtof(str.c_str());
    //std::cout << "atof - DOUBLE:" << num_int << std::endl;
    float num_float = doubleToFloat(num_double);
    //std::cout << "FLOAT:" << num_float << std::endl;

    print_nums(num_int, num_float, num_double);
	// if (num_double - num_int == 0)
	//     return handleInt(num_int);
	// return handleFloatOrDouble(num_double);
}
