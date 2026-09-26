/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:04:43 by slambert          #+#    #+#             */
/*   Updated: 2026/09/26 11:47:47 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>

std::string format_float(float value)
{
    std::ostringstream oss;
    
    for (int i = 1; i <= 50; i++)
    {
        oss.str("");
        oss << std::fixed << std::setprecision(i) << value;
        if (strtof(oss.str().c_str(), NULL) == value)
            break;
    }
    return (oss.str());
}

std::string format_double(double value)
{
    std::ostringstream oss;
    
    for (int i = 1; i <= 330; i++)
    {
        oss.str("");
        oss << std::fixed << std::setprecision(i) << value;
        if (strtod(oss.str().c_str(), NULL) == value)
            break;
    }
    return (oss.str());
}
