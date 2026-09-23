/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:19:59 by slambert          #+#    #+#             */
/*   Updated: 2026/09/23 15:01:06 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool is_float(const std::string &str)
{
    return !str.empty() && str[str.length() - 1] == 'f';
}

static bool is_double(const std::string &str)
{
    return !str.empty() && str.find(".") != str.npos;
}

enum e_type get_type(const std::string &str)
{
    if (is_float(str))
        return FLOAT;
    if (is_double(str))
        return DOUBLE;
    return INT;
}
