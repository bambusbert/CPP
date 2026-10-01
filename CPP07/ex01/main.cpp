/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/10/01 16:39:08 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>

template <typename T> void print_elem(const T& elem)
{
    std::cout << elem << std::endl;
}

void increment_int(int &num)
{
    num++;
}

template <typename T> void increment_tpl(T& num)
{
    num++;
}

void append_shit_to_string(std::string& str)
{
    str.append("end");
}

int main (void)
{
    std::cout << "Test 0: String array & print_elem" << std::endl;
    std::string strarr[] = {"asd", "fgh", "jkl"};
    ::iter(strarr, sizeof(strarr) / sizeof(strarr[0]), print_elem);
    std::cout << std::endl;
    
    std::cout << "Test 1: String array & print_elem - const" << std::endl;
    const std::string const_strarr[] = {"asd", "fgh", "jkl"};
    ::iter(const_strarr, sizeof(const_strarr) / sizeof(const_strarr[0]), print_elem);
    
    std::cout << "\nTest 2: Int array: increment & print_elem" << std::endl;
    int intarr[] = {1,2,3,4,5};
    ::iter(intarr, sizeof(intarr) / sizeof(int), increment_tpl);
    ::iter(intarr, sizeof (intarr) / sizeof(int), print_elem);

    std::cout << "\nTest 3: appending 'end' to strings & print_elem" << std::endl;
    ::iter(strarr, sizeof(strarr) / sizeof(strarr[0]), append_shit_to_string);
    ::iter(strarr, sizeof(strarr) / sizeof(strarr[0]), print_elem);

    std::cout << "\nTest 4: int array and increment_tpl" << std::endl;
    int intarr2[] = {1, 2, 3, 4, 5};
    ::iter(intarr2, 5, increment_tpl);
    ::iter(intarr2, 5, print_elem);
}
