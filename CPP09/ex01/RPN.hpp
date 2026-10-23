/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 13:04:53 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 16:34:20 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <string>
#include <list>
#include <iostream>

class RPN
{
    private:
        std::list<long> _lst;
        void parse_string(const std::string &str);
        int execute_operation(long *res, char c);
        long execute_addition();
        long execute_subtraction();
        long execute_multiplication();
        int execute_division(long *res);
        void parse_char_to_long_and_add_to_list(char c);
    public:
        RPN();
        RPN(const std::string& str);
        ~RPN();
        RPN(const RPN& other);
        RPN&operator=(const RPN& other);
};

#endif
