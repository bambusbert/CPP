/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/10/01 17:20:55 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T> void print_arr(T* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << "Element " << i << ": " << arr[i] << std::endl;
}

int main (void)
{
    std::cout << "Test 1: Default constructor & int array" << std::endl;
    Array<int>empty;    
    Array<int>non_empty(5);
    for(size_t i = 0; i < 5; i++)
        non_empty[i] = i * 2;
    print_arr(&non_empty[0], non_empty.size());
    
    std::cout << "\nTest 2: copy constructor, modifying value" << std::endl;
    Array<int> non_empty2(non_empty);
    non_empty2[2] = 77;
    std::cout << "non empty" << std::endl;
    print_arr(&non_empty[0], non_empty.size());
    std::cout << std::endl;
    std::cout << "non empty 2" << std::endl;
    print_arr(&non_empty2[0], non_empty2.size());
    std::cout << std::endl;
    
    std::cout << "\nTest 3: copy assignment operator" << std::endl;
    Array<int>non_empty3;
    non_empty3 = non_empty;
    std::cout << "non empty 3" << std::endl;
    print_arr(&non_empty3[0], non_empty3.size());
    
    std::cout << "\nTest 4: std::string array" << std::endl;
    Array<std::string> strarr(7);
    for (size_t i = 0; i < 7; i++)
    {
        strarr[i] = "str";
        strarr[i].append(i + 1, '*');
    }
    strarr[6] = "adasffgrgregergeg";
    print_arr(&strarr[0], strarr.size());
    
    std::cout << "\nTest 5: exceptions" << std::endl;
    //test out of bounds exception
    try
    {
        strarr[7] = "blub";
    }
    catch(const std::exception& e)
    {
        std::cerr << "operation unsuccessful. " << e.what() << '\n';
    }
    
    try
    {
        strarr[-1] = "blub";
    }
    catch(const std::exception& e)
    {
        std::cerr << "operation unsuccessful. " << e.what() << '\n';
    }

    //test if i get a compiler warning here 
    // std::cout << "new test" << std::endl;
    // const Array<int> a(3);
    // a[0] = 42;


    // std::cout << std::endl;
    // std::cout << std::endl;
    // int *a = new int(); //initialized to 0
    // int *b = new int;   //garbage value
    // std::cout << (*a) << std::endl;
    // //std::cout << (*b) << std::endl;
    // //this one gives valgrind errors because it still holds garbage values
    // //because it is default initialized
    // //a is direct-initialized
    // delete(a);
    // delete(b);
}
