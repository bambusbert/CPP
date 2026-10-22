/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:16:46 by slambert          #+#    #+#             */
/*   Updated: 2026/10/22 21:19:52 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <iterator>
#include <algorithm>

class BitcoinExchange
{
    private:
        std::map<std::string, double> rates;
        int initialize_prices();
        int loop_input_file(const std::string &filename);
        bool init_successful;
    public: 
        BitcoinExchange();
        BitcoinExchange(const std::string &filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void print_daily_prices();
        bool get_init_successful();
    
};

#endif
