/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/09/29 16:52:43 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T> void print_arr(T* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << "Element " << i << ": " << arr[i] << std::endl;
} 

int main (void)
{
    Array<int>empty;    
    Array<int>non_empty(5);
    for(size_t i = 0; i < 5; i++)
        non_empty.getArray()[i] = i;
    Array<int> non_empty2(non_empty);
    non_empty2.getArray()[2] = 77;
    print_arr(non_empty.getArray(), non_empty.getSize());
    std::cout << std::endl;
    print_arr(non_empty2.getArray(), non_empty2.getSize());
}
