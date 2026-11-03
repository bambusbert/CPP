/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:47:36 by slambert          #+#    #+#             */
/*   Updated: 2026/11/03 14:22:02 by slambert         ###   ########.fr       */
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
#include <algorithm>

class PMergeMe
{
    template <typename T>
    struct IdxLessTemp
    {
    private:
        const T &_v;
    public:
        int *_count;
        IdxLessTemp(const T &v, int *count) : _v(v), _count(count) {}
        bool operator()(int i, int j) const
        {
            ++(*_count);
            return _v[i] < _v[j];
        }
    };

private:
    std::vector<int> _con_vec;
    std::deque<int> _con_deq;
    long _t_vec;
    long _t_deq;
    template <typename T>
    T sort_container(T &values, T &indices);
    template <typename T>
    T indices_2_values(T &con_val, T &con_ind);
    template <typename T>
    void print_container(T &con);
public:
    PMergeMe();
    ~PMergeMe();
    PMergeMe(const PMergeMe &other);
    PMergeMe &operator=(const PMergeMe &other);
    bool validate_input_and_fill_containers(char **argv);
    void sort_containers();
    void print_vec();
    void print_deq();
    void print_timings();
};

#endif
