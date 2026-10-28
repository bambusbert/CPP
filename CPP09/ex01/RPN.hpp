/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:04:53 by slambert          #+#    #+#             */
/*   Updated: 2026/10/28 15:01:27 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#define FAIL -1
#define SUCCESS 0

#include <string>
#include <list>
#include <iostream>

class RPN
{
    private:
        std::list<long> _lst;
        std::string _str;
        int execute_operation(long *res, char c);
        long execute_addition();
        long execute_subtraction();
        long execute_multiplication();
        int execute_division(long *res);
        void parse_char_to_long_and_add_to_list(char c);
        void insert_result (long &res);
    public:
        RPN();
        RPN(const std::string& str);
        ~RPN();
        RPN(const RPN& other);
        RPN&operator=(const RPN& other);
        void parse_string();
};

#endif
