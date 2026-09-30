/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/09/30 14:38:17 by slambert         ###   ########.fr       */
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


void print_int_const(const int& num)
{
    std::cout << num << std::endl;
}

template <typename T> void print_arr(T* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << "Element " << i << ": " << arr[i] << std::endl;
}

void append_shit_to_string(std::string& str)
{
    str.append("end");
}

int main (void)
{
    std::cout << "String" << std::endl;
    std::string strarr[] = {"asd", "fgh", "jkl"};
    ::iter(strarr, sizeof(strarr) / sizeof(strarr[0]), print_elem<std::string>);
    std::cout << std::endl;
    const std::string strarr2[] = {"asd", "fgh", "jkl"};
    ::iter(strarr2, sizeof(strarr2) / sizeof(strarr2[0]), print_elem<const std::string>);
    
    std::cout << "\nInt array" << std::endl;
    int intarr[] = {1,2,3,4,5};
    ::iter(intarr, sizeof(intarr) / sizeof(int), increment_int);
    print_arr(intarr, sizeof (intarr) / sizeof(int));
    ::iter(intarr, sizeof (intarr) / sizeof(int), print_int_const);

    std::cout << "\nappending 'end' to strings" << std::endl;
    ::iter(strarr, sizeof(strarr) / sizeof(strarr[0]), append_shit_to_string);
    print_arr(strarr, sizeof(strarr) / sizeof(strarr[0]));
    

    std::cout << "\nconst arr, print_elem called without instantiation" << std::endl;
    const std::string strarr3[] = {"asd", "fgh", "jkl"};
    ::iter(strarr3, 3, print_elem);

    std::cout << "\nint array and increment_tpl" << std::endl;
    int intarr2[] = {1, 2, 3, 4, 5};
    ::iter(intarr2, 5, increment_tpl);
    print_arr(intarr2, 5);
}
