/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:47 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 18:27:58 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if(argc == 1)
		return (std::cerr << "Error. no argument. Usage: ./PMergeMe arg0 arg1 arg2 ... (only positive integers as args)" << std::endl, 1);
	PMergeMe vec;
	if (vec.validate_input_and_fill_containers(argv) == false)
		return (std::cerr << "Error" << std::endl, 1);
	//std::cout << "all gud" << std::endl;
	
	return 0;
}
