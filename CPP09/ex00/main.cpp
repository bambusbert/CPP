/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:47 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 12:05:16 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "wrong number of arguments" << std::endl, 1);
	BitcoinExchange btc(argv[1]);
	BitcoinExchange btc2(btc);
	BitcoinExchange btc3;
	btc3 = btc2;
	
	std::cout << std::endl << "copy constructor" << std::endl;
	btc2.print_daily_prices();
	std::cout << std::endl << "copy assignment operator" << std::endl;
	btc3.print_daily_prices();
	
	return 0;
}
