/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/10/05 18:44:07 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <string>
#include "easyfind.hpp"

template <typename T> void print_container(T& t)
{
    typename T::iterator it;
    for (it = t.begin(); it != t.end(); ++it)
        std::cout << *it << std::endl;
}

int main (void)
{
    std::vector<int> v = {1,2,3,4};
    //std::vector<int>::iterator it;
    //std::vector<int>::iterator it;
    v.push_back(5);
    // for (it = v.begin(); it != v.end(); it++)
    //     std::cout << *it << std::endl;
    print_container(v);
    v.pop_back();
    std::cout << "Element at index 0: " << v.at(0)<< std::endl;
    v.insert(v.begin(), 789);
    print_container(v);

    int num_2_find = 4;
    // std::vector<int>::iterator int_found = std::find(v.begin(), v.end(), num_2_find);
    std::vector<int>::iterator int_found = easyfind(v, num_2_find);
    
    if (int_found == v.end())
        std::cout << "not found" << std::endl;
    else 
        std::cout << "found: " << *int_found << std::endl;
    
    std::cout << "LIST SHIT" << std::endl;
    std::list<std::string> strlist = {"elem1", "elem2", "elem3"};
    print_container(strlist);
    strlist.pop_front();
    strlist.push_front("elem0");
    std::cout << std::endl;
    print_container(strlist);
    
    std::string str_2_find = "elem3";
    std::list<std::string>::iterator str_found = std::find(strlist.begin(), strlist.end(), str_2_find);
    if (str_found == strlist.end())
        std::cout << "not found" << std::endl;
    else 
        std::cout << "found: " << *str_found << std::endl;
}