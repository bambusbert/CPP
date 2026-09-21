/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:30:46 by slambert          #+#    #+#             */
/*   Updated: 2026/09/21 13:35:23 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

//scientific notation is not allowed
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Enter exactly 1 argument" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
}
