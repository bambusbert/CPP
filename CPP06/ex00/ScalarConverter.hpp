/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:54 by slambert          #+#    #+#             */
/*   Updated: 2026/09/26 11:49:40 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cmath>
#include <iomanip>
#include <cfloat>

enum e_type { INT, FLOAT, DOUBLE };
enum e_type get_type(const std::string &str);
std::string format_float(float value);
std::string format_double(double value);

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string &str);
};

#endif
