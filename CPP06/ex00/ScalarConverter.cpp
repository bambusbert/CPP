/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:55 by slambert          #+#    #+#             */
/*   Updated: 2026/09/04 16:02:50 by slambert         ###   ########.fr       */
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

static void print_char(int num)
{
    if (num >= 32 && num <= 126)
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    else
        std::cout << "char: Non displayable"  << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " <<  static_cast<float>(num) << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
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
	std::cout << "float: " <<  num_float;
    if (num_float - std::floor(num_float) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;
	std::cout << "double: " << num_double;
    if (num_double - std::floor(num_double) == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

static void handleChar(char c)
{
    print_nums(static_cast<long>(c), static_cast<float>(c), static_cast<double>(c));
}

static long myAtoi(const char *str, bool* impossible)
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
            return (-1);
        ret *= 10;
        ret += str[i] - 48;
        if (ret == static_cast<long>(INT_MAX) + 1 && minus)
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
    return ret;
}

static float doubleToFloat(double num_double)
{
    return static_cast<float>(num_double);
}

void print_impossible()
{
    std::cout << "char: impossible"  << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool is_impossible(std::string str)
{
    //only numbers, max 1 dot, max 1 d or f in the end
    int c_dot = 0;
    int c_f = 0;
    int c_d = 0;
    int i = -1;
    std::string allowed = "0123456789.df";
    
    while (str[++i])
    {
        if (allowed.find(str[i]) == allowed.npos)
            return false;
        if (str[i] == '.')
            c_dot++;
        else if (str[i] == 'd')
            c_d++;
        else if (str[i] == 'f')
            c_f++;
    }
    if (c_dot > 1)
        return false;
    if ((c_d > 1 || c_f > 1) && (str[i-1] != 'd' && str[i-1] != 'f'))
        return false;
    return true;    
}

static bool is_literal(std::string str)
{
    
}

static void print_literal(std::string str)
{
    
}

// allowed is:
// atof: returns double, argument C string
// atoi: returns int, argument C string
void ScalarConverter::convert(std::string str)
{
	if (str.length() == 1 && static_cast<int>(str[0]) >= 32 && static_cast<int>(str[0]) <= 126)
	{
		if (!(str[0] >= '0' && str[0] <= '9'))
			return handleChar(str[0]);
	}
    if (is_impossible(str))
        return print_impossible();
    if (is_literal(str))
        return print_literal(str);
    bool int_imp = false;
	long num_int = myAtoi(str.c_str(), &int_imp);
    if (num_int == -1 && int_imp)
        num_int = static_cast<long>(INT_MIN) - 1;
	double num_double = myAtof(str.c_str());
    if (std::isnan(num_double))
        return print_impossible();
    float num_float = doubleToFloat(num_double);
    if (!int_imp)
        num_int = static_cast<int>(num_double);
    print_nums(num_int, num_float, num_double);
}
