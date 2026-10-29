/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:47:36 by slambert          #+#    #+#             */
/*   Updated: 2026/10/29 16:52:19 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.youtube.com/watch?v=4VqmGXwpLqc

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <iostream>
#include <iterator>
// #include <sys/time.h>
#include <time.h>

class PMergeMe
{
    private:
        std::vector<int> _con_vec;
        std::deque<int> _con_deq;
        long _t_vec;
        long _t_deq;
        // void sort_deq(double *t_deq);
        // void sort_vec(double *t_vec);
        template <typename T>
        T sort_container(T &con);
        template <typename T>
        T sort_container2(T &values, T& indices);
        template <typename T>
        T merge_container(T& left, T& right);
        template <typename T>
        T indices_2_values(T& con, T& val);
    public:
	    PMergeMe();
	    ~PMergeMe();
	    PMergeMe(const PMergeMe &other);
	    PMergeMe &operator=(const PMergeMe &other);
        bool validate_input_and_fill_containers(char **argv);
        void sort_containers();
        template <typename T>
        void print_container(T& con);
        void print_vec();
        void print_deq();
        void print_timings();
};

#endif
