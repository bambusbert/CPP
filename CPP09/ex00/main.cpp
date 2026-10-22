/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:47 by slambert          #+#    #+#             */
/*   Updated: 2026/10/22 16:45:14 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "wrong number of arguments" << std::endl, 1);
	BitcoinExchange btc(argv[1]);
    if (!btc.get_init_successful())
		return (std::cout << "error while initializing" << std::endl, 1);  
    //btc.print_daily_prices();	//debug

	return 0;
}
