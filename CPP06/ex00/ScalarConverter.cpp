/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:55 by slambert          #+#    #+#             */
/*   Updated: 2026/09/26 11:16:58 by slambert         ###   ########.fr       */
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

static void special_char_handler(bool int_overflow, int num_int)
{
    if (int_overflow || num_int > 127 || num_int < 0)
        std::cout << "char: impossible"  << std::endl;
    else
        std::cout << "char: Non displayable"  << std::endl;
}

static void print_nums(bool int_overflow, int num_int, bool float_overflow, float num_float, double num_double)
{
    if (num_int >= 32 && num_int <= 126)
        std::cout << "char: '" << static_cast<char>(num_int) << "'" << std::endl;
    else
        special_char_handler(int_overflow, num_int);
    if (int_overflow)
        std::cout << "int: impossible" << std::endl;
    else
	    std::cout << "int: " << num_int << std::endl;
    if (float_overflow)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << format_float(num_float) << "f" << std::endl;
    std::cout << "double: " << format_double(num_double) << std::endl;
}

static void handleChar(char c)
{
    print_nums(false, static_cast<int>(c), false, static_cast<float>(c), static_cast<double>(c));
}

//i later found about the 
static bool is_impossible(const std::string& str)
{
    int c_dot = 0;
    int c_f = 0;
    int i = -1;
    int c_nums = 0;
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
        else if (str[i] >= '0' && str[i] <= '9')
            c_nums++; 
    }
    if (c_dot > 1 || c_f > 1)
        return true;
    if (c_f == 1 && str[i - 1] != 'f')
        return true;
    if (c_f == 1 && c_dot != 1)
        return true;
    if (c_nums == 0)
        return true;
    return false;    
}

static void print_literal(const std::string& str1, const std::string& str2)
{
    std::cout << "char: impossible"  << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str1 << std::endl;
    std::cout << "double: " << str2 << std::endl;
}

static bool literal_handler(const std::string& str)
{
    if (str == "inff" || str == "+inff" || str == "inf" || str == "+inf")
        return (print_literal("inff", "inf"), true);
    else if (str == "-inff" || str == "-inf")
        return (print_literal("-inff", "-inf"), true);
    else if (str == "nan" || str == "+nan" || str == "-nan" || str == "nanf" || str == "+nanf" || str == "-nanf")
        return (print_literal("nanf", "nan"), true);
    return false;
}

static void double_handler(const std::string& str)
{
    bool int_overflow = false;
    bool float_overflow = false;
    errno = 0;
    double num_double = strtod(str.c_str(), NULL);
    if (errno == ERANGE && (num_double == HUGE_VAL || num_double == -HUGE_VAL))
        return print_literal("impossible", "impossible");
    float num_float = 0;
    if (num_double < static_cast<double>(-FLT_MAX) || num_double > static_cast<double>(FLT_MAX))
        float_overflow = true;
    else
        num_float = static_cast<float>(num_double);
    int num_int = 0;
    if (num_double >= static_cast<double>(INT_MAX) + 1 || num_double <= static_cast<double>(INT_MIN) - 1)
        int_overflow = true;
    else
        num_int = static_cast<int>(num_double);  
    print_nums(int_overflow, num_int, float_overflow, num_float, num_double);
}

static void float_handler(const std::string& str)
{
    bool int_overflow = false;
    errno = 0;
    float num_float = strtof(str.c_str(), NULL);
    if (errno == ERANGE && (num_float == HUGE_VALF || num_float == -HUGE_VALF))    //float overflow
        return print_literal("impossible", "impossible");
    double num_double = static_cast<double>(num_float);
    int num_int = 0;
    if (num_double <= static_cast<double>(INT_MIN) - 1 || num_double >= static_cast<double>(INT_MAX) + 1)
        int_overflow = true;
    else
        num_int = static_cast<int>(num_float);
    print_nums(int_overflow, num_int, false, num_float, num_double);
}

static void int_handler(const std::string& str)
{
    errno = 0;
    long num_long = strtol(str.c_str(), NULL, 10);
    if (errno == ERANGE)
        return print_literal("impossible", "impossible");
    if (num_long < static_cast<long>(INT_MIN) || num_long > static_cast<long>(INT_MAX))
        return print_literal("impossible", "impossible");
    int num_int = static_cast<int>(num_long);
    float num_float = static_cast<float>(num_int);
    double num_double = static_cast<double>(num_int);
    print_nums(false, num_int, false, num_float, num_double);
}


void ScalarConverter::convert(const std::string &str)
{
	if (str.length() == 1 && static_cast<int>(str[0]) >= 32 && static_cast<int>(str[0]) <= 126)
	{
		if (!(str[0] >= '0' && str[0] <= '9'))
			return handleChar(str[0]);
	}
    if (literal_handler(str))
        return ;
    if (is_impossible(str))
        return print_literal("impossible", "impossible");
    e_type type = get_type(str);
    if (type == FLOAT)
        float_handler(str);
    else if (type == DOUBLE)
        double_handler(str);
    else if (type == INT)
        int_handler(str);
}
