/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:47 by slambert          #+#    #+#             */
/*   Updated: 2026/10/21 19:55:38 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
    if (!btc.get_init_successful())
    {
		std::cout << "error while initializing" << std::endl;
        return 1;      
    }
    btc.print_daily_prices();

	return 0;
}
