/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:47:36 by slambert          #+#    #+#             */
/*   Updated: 2026/11/10 17:26:49 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstddef>

#define DEBUG 0

class PmergeMe
{
    template <typename T>
    struct IndexValueLess
    {
        private:
            const T *_v;
            int *_count;
            
        public:
            IndexValueLess();
            IndexValueLess(const T *v, int *count);
            ~IndexValueLess();
            IndexValueLess(const IndexValueLess &other);
            IndexValueLess &operator=(const IndexValueLess &other);
            bool operator()(int i, int j) const;
    };

    private:
        std::vector<int> _con_vec;
        std::deque<int> _con_deq;
        long _t_vec;
        long _t_deq;
        int _vec_ops;
        int _deq_ops;
        
        template <typename T>
        T sort_container(T &values, T &indices, int *op_count);
        template <typename T>
        T indices_2_values(T &con_val, T &con_ind);
        template <typename T>
        void print_container(T &con);
        
        template <typename T>
        void loser_handler(T &a, T &b, T& partners, T& values, int *count);
        unsigned int update_index(unsigned int count_elems, unsigned int size_b, unsigned int& prev_jacob, unsigned int &cur_jacob);
        template <typename T>
        T update_b(T &a, T &b_old, T &partners);
        unsigned int next_jacobsthal(unsigned int num);
        
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        
        bool validate_input_and_fill_containers(char **argv);
        void sort_containers();
        void print_vec();
        void print_deq();
        void print_timings();
};

#include "PmergeMe.tpp"

#endif
