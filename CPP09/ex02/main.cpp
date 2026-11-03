/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:47 by slambert          #+#    #+#             */
/*   Updated: 2026/11/03 10:26:02 by slambert         ###   ########.fr       */
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

// #include <vector>

// int main(int argc, char **argv)
// {
// 	std::vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
// 	v.push_back(4);
// 	v.push_back(5);
// 	v.push_back(7);
// 	const std::vector<int>::iterator vit = v.b
	
// 	return 0;
// }