/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:47:36 by slambert          #+#    #+#             */
/*   Updated: 2026/10/23 18:33:52 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <iostream>

class PMergeMe
{
    private:
        std::vector<int> _con_vec;
        std::deque<int> _con_deq;
        // void sort_deq(double *t_deq);
        // void sort_vec(double *t_vec);
        template <typename T>
        void sort_container(T con, double *time);
    public:
	    PMergeMe();
	    ~PMergeMe();
	    PMergeMe(const PMergeMe &other);
	    PMergeMe &operator=(const PMergeMe &other);
        bool validate_input_and_fill_containers(char **argv);
        void sort_containers(double *t_vec, double *t_deq);

};

#endif
