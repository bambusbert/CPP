/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:55 by slambert          #+#    #+#             */
/*   Updated: 2026/09/21 13:39:38 by slambert         ###   ########.fr       */
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

static void print_nums(long num_int, float num_float, double num_double)
{
    if (num_int >= 32 && num_int <= 126)
        std::cout << "char: " << static_cast<char>(num_int) << std::endl;
    else if (num_int != static_cast<long>(INT_MIN) - 1)
        std::cout << "char: Non displayable"  << std::endl;
    else
        std::cout << "char: impossible"  << std::endl;
    if (num_int == static_cast<long>(INT_MIN) - 1)
        std::cout << "int: impossible" << std::endl;
    else
	    std::cout << "int: " << num_int << std::endl;
    if (num_float == -0)
        num_float = 0;
    if (num_double == -0)
        num_double = 0;
    std::cout << "float: " << std::fixed << std::setprecision(num_float == std::floor(num_float) ? 1 : 6) << num_float;
    std::cout << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(num_double == std::floor(num_double) ? 1 : 6) << num_double;
    std::cout << std::endl;
}

static void handleChar(char c)
{
    print_nums(static_cast<long>(c), static_cast<float>(c), static_cast<double>(c));
}

static float doubleToFloat(double num_double)
{
    return static_cast<float>(num_double);
}

static bool is_impossible(std::string str)
{
    int c_dot = 0;
    int c_f = 0;
    int i = -1;
    std::string allowed = "0123456789.f";
    
    if (!str[0])
        return true;
    if (str[0] == '+' || str[0] == '-')
        i++;
    while (str[++i])
    {
        if (allowed.find(str[i]) == allowed.npos)
            return true;
        if (str[i] == '.')
            c_dot++;
        else if (str[i] == 'f')
            c_f++;
    }
    if (c_dot > 1 || c_f > 1)
        return true;
    if (c_f == 1 && str[i - 1] != 'f')
        return true;
    return false;    
}

static void print_literal(std::string str1, std::string str2)
{
    std::cout << "char: impossible"  << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str1 << std::endl;
    std::cout << "double: " << str2 << std::endl;
}

static bool literal_handler(std::string str)
{
    if (str == "inff" || str == "+inff" || str == "inf" || str == "+inf")
        return (print_literal("+inff", "+inf"), true);
    else if (str == "-inff" || str == "-inf")
        return (print_literal("-inff", "-inf"), true);
    return false;
}

void ScalarConverter::convert(std::string str)
{
	if (str.length() == 1 && static_cast<int>(str[0]) >= 32 && static_cast<int>(str[0]) <= 126)
	{
		if (!(str[0] >= '0' && str[0] <= '9'))
			return handleChar(str[0]);
	}
    if (literal_handler(str))
        return ;
    if (is_impossible(str))
    {
        return print_literal("impossible", "impossible");
    }
	double num_double = atof(str.c_str());
    if (std::isnan(num_double))
        return print_literal("impossible", "impossible");
    float num_float = doubleToFloat(num_double);
    long num_int;
    if (num_double > INT_MAX || num_double < INT_MIN)
        num_int = static_cast<long>(INT_MIN) - 1;
    else
        num_int = static_cast<long>(num_double);  
    print_nums(num_int, num_float, num_double);
}
