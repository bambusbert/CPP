/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/10/07 15:25:30 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
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
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Test from subject2 - list instead of MutantStack" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    
    
    std::cout << "\nEND OF SUBJECT TEST" << std::endl;
    
    std::cout << "\nTest 0: MutantStack with explicitly chosen container" << std::endl;
    MutantStack<int, std::list<int> > list_mutant;
    list_mutant.push(1);
    list_mutant.push(2);
    list_mutant.push(3);
    list_mutant.push(4);
    MutantStack<int, std::list<int> >::iterator it2 = list_mutant.begin();
    MutantStack<int, std::list<int> >::iterator ite2 = list_mutant.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    
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
