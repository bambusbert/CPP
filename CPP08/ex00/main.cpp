/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/10/06 11:38:28 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <vector>
#include <list>
#include <deque>
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

template <typename T>
void display_found (T found_elem, T end)
{
    if (found_elem == end)
        std::cout << "not found" << std::endl;
    else 
        std::cout << "found: " << *found_elem << std::endl;
}

int main (void)
{
    std::cout << "Playing around" << std::endl;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    print_container(v);
    v.pop_back();
    std::cout << "Element at index 0: " << v.at(0)<< std::endl;
    v.insert(v.begin(), 789);
    print_container(v);

    std::cout << "\nTest 0 - Vector: number in container" << std::endl;
    int num_2_find = 4;
    std::vector<int>::iterator int_found = easyfind(v, num_2_find);
    display_found(int_found, v.end());
    
    std::cout << "\nTest 1 - Vector: number not in container" << std::endl;
    num_2_find = 78;
    int_found = easyfind(v, num_2_find);
    display_found(int_found, v.end());

    std::cout << "\nTest 2 - List: number not in container CONST" << std::endl;
    //now our result variable has to be of type const_iterator
    //this does not compile bc initialization by initializer list is forbidden.
    //to execute this test we have to remove the flags first
    // const std::list<int> list = {4,5,6,7};
    const std::list<int> list;
    num_2_find = 4;
    std::list<int>::const_iterator int_found_const = easyfind(list, num_2_find);
    display_found(int_found_const,list.end());

    std::cout << "\nTest 3 - Deqeue: number in container" << std::endl;
    std::deque<int> q;
    q.push_back(5);
    q.push_back(6);
    q.push_back(8);
    q.push_back(10);
    num_2_find = 8;
    std::deque<int>::iterator qi = easyfind(q, num_2_find);
    display_found(qi, q.end()); 
    
    std::cout << "\nTest 4 - Deqeue: number not in container" << std::endl;
    num_2_find = 9;
    qi = easyfind(q, num_2_find);
    display_found(qi, q.end()); 
    
    // std::cout << "LIST SHIT" << std::endl;
    // std::list<std::string> strlist = {"elem1", "elem2", "elem3"};
    // print_container(strlist);
    // strlist.pop_front();
    // strlist.push_front("elem0");
    // std::cout << std::endl;
    // print_container(strlist);
    
    // std::string str_2_find = "elem3";
    // std::list<std::string>::iterator str_found = std::find(strlist.begin(), strlist.end(), str_2_find);
    // if (str_found == strlist.end())
    //     std::cout << "not found" << std::endl;
    // else 
    //     std::cout << "found: " << *str_found << std::endl;
    // str_2_find = "asd";
    // str_found = std::find(strlist.begin(), strlist.end(), str_2_find);
    // if (str_found == strlist.end())
    //     std::cout << "not found" << std::endl;
    // else 
    //     std::cout << "found: " << *str_found << std::endl;
}
