/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:04:43 by slambert          #+#    #+#             */
/*   Updated: 2026/09/23 15:07:38 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

std::string format_float(float value)
{
    std::ostringstream oss;
    if (value == std::floor(value))
    {
        oss << std::fixed << std::setprecision(1) << value;
        return oss.str();
    }
    for (int p = 1; p <= 9; p++)        // 9 significant digits always round-trip a float
    {
        oss.str("");
        oss << std::setprecision(p) << value;
        if (strtof(oss.str().c_str(), NULL) == value)
            break;
    }
    return oss.str();
}

std::string format_double(double value)
{
    std::ostringstream oss;
    if (value == std::floor(value))
    {
        oss << std::fixed << std::setprecision(1) << value;
        return oss.str();
    }
    for (int p = 1; p <= 17; p++)       // 17 significant digits always round-trip a double
    {
        oss.str("");
        oss << std::setprecision(p) << value;
        if (strtod(oss.str().c_str(), NULL) == value)
            break;
    }
    return oss.str();
}
