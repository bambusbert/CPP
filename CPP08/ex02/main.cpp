/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/10/07 14:43:06 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <iterator>

int main()
{
    std::cout << "Test from subject" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "\n\nprint whole stack with iterator" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\nEND OF SUBJECT TEST" << std::endl;
    it = mstack.begin();

    std::cout << "\nTest 1: copy constructor" << std::endl;
    {
        MutantStack<int> copy(mstack);
        MutantStack<int>::iterator c_it = copy.begin();
        MutantStack<int>::iterator c_ite = copy.end();
        int save = *it;
        *it = 555555;
        while (c_it != c_ite)
        {
            std::cout << *c_it << std::endl;
            ++c_it;
        }
        *it = save;
    }

    std::cout << "\nTest 2: copy assignment operator" << std::endl;
    {
        MutantStack<int> copy;
        copy = mstack;
        MutantStack<int>::iterator c_it = copy.begin();
        MutantStack<int>::iterator c_ite = copy.end();
        int save = *it;
        *it = 555555;
        while (c_it != c_ite)
        {
            std::cout << *c_it << std::endl;
            ++c_it;
        }
        *it = save;
    }

    return 0;
}
