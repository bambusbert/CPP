/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:10:03 by slambert          #+#    #+#             */
/*   Updated: 2026/11/04 13:43:45 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::print_vec()
{
	print_container(_con_vec);
}

void PmergeMe::print_deq()
{
	print_container(_con_deq);
}

void PmergeMe::print_timings()
{
	std::cout << "Time to process a range of " << _con_vec.size()
			  << " elements with std::vector : " << _t_vec << " ns" << std::endl;
	std::cout << "Time to process a range of " << _con_vec.size()
			  << " elements with std::deque  : " << _t_deq << " ns" << std::endl;
	if (DEBUG)
	{	
		std::cout << "Operations needed (std::vector): " << _vec_ops << std::endl;
		std::cout << "Operations needed (std::deque): " << _deq_ops << std::endl;
	}
}
