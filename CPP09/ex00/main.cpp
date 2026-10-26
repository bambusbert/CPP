/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:47 by slambert          #+#    #+#             */
/*   Updated: 2026/10/26 10:52:54 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//data.csv stores prices
//input.csv stores amount (value) of btc
//output is the multiplication of these 2 variables
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error. wrong number of arguments. Usage: ./btc input.txt" << std::endl, 1);
	BitcoinExchange btc(argv[1]);
	btc.loop_input_file();

	return 0;
}

// TEST main
// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (std::cout << "wrong number of arguments" << std::endl, 1);
// 	// BitcoinExchange btc(argv[1]);
// 	BitcoinExchange *btc = new BitcoinExchange((argv[1]));
// 	BitcoinExchange btc2(*btc);
// 	BitcoinExchange btc3;
// 	btc3 = btc2;
	
// 	delete(btc);
// 	// std::cout << "\nbtc" << std::endl;
// 	// (*btc).loop_input_file(); ,

 // 	std::cout << "\nbtc2" << std::endl;
// 	btc2.loop_input_file();
// 	std::cout << "\nbtc3" << std::endl;
// 	btc3.loop_input_file();
// 	// std::cout << std::endl << "copy constructor" << std::endl;
// 	// btc2.print_daily_prices();
// 	// std::cout << std::endl << "copy assignment operator" << std::endl;
// 	// btc3.print_daily_prices();
	
// 	return 0;
// }
