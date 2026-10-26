/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:47 by slambert          #+#    #+#             */
/*   Updated: 2026/10/26 17:20:10 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if(argc == 1)
		return (std::cerr << "Error. no argument. Usage: ./PMergeMe arg0 arg1 arg2 ... (only positive integers as args)" << std::endl, 1);
	PMergeMe pm;
	if (pm.validate_input_and_fill_containers(argv) == false)
		return (std::cerr << "Error" << std::endl, 1);
	//std::cout << "all gud" << std::endl;
	
	std::cout << "Before: ";
	pm.print_vec();
	pm.sort_containers();
	std::cout << "After:  ";
	pm.print_vec();
	// pm.print_containers();
	pm.print_timings();
	return 0;
}
