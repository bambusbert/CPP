/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:16:46 by slambert          #+#    #+#             */
/*   Updated: 2026/11/10 12:22:39 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#define FAIL (-1)
#define SUCCESS 0
#define YEAR_MAX 2035

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cerrno>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _rates;
        std::string _input_file;
        bool _init_successful;
        int initialize_rates();
        void parse_single_quantity_line(const std::string &line) const;
        double return_price_for_date(const std::string &date) const;
        int check_syntax_left(int *year, int *month, int *day, std::string &left) const;
        int check_syntax_right(double *val_right, std::string &right) const;
        void display_result (const std::string &date, const double &amount_traded) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        bool get_init_successful() const;
        int loop_quantity_file() const;
};

int strtod_wrapper(double *res, const std::string &str);
int strtol_wrapper(int *res, const std::string &str);

#endif
