/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:16:46 by slambert          #+#    #+#             */
/*   Updated: 2026/10/21 19:54:53 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iterator>

class BitcoinExchange
{
    private:
        std::map<std::string, double> rates;
        bool init_successful;
    public: 
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        int initialize();
        void print_daily_prices();
        bool get_init_successful();
    
};

#endif
