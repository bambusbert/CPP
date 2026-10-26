/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:47 by slambert          #+#    #+#             */
/*   Updated: 2026/10/26 15:48:21 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if(argc != 2)
		return (std::cerr << "Error. no argument. Usage: ./RPN arg" << std::endl, 1);
	RPN r(argv[1]);
	r.parse_string();
	return 0;
}

//test main

// int main(int argc, char **argv)
// {
// 	if(argc != 2)
// 		return (std::cerr << "Error. no argument. Usage: ./RPN arg" << std::endl, 1);
// 	RPN *r = new RPN(argv[1]);
// 	(*r).parse_string();
// 	RPN r2(*r);
// 	delete(r);
// 	r2.parse_string();
// 	return 0;
// }
