/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/10/27 14:56:17 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>
#include <algorithm>
#include <list>

int main(void)
{
    std::cout << "Test 0: number constructor" << std::endl;
    Span* s = new Span(3);
    (*s).addNumber(-1);
    (*s).addNumber(2);
    (*s).addNumber(3);
    (*s).printNums();

    std::cout << "\nTest 1: copy constructor" << std::endl;
    Span copy(*s);
    copy.printNums();

    std::cout << "\nTest 2: copy assignment operator" << std::endl;
    Span b(3);
    b.addNumber(10);
    b.addNumber(20);
    b.addNumber(30);
    b = *s;
    delete (s);
    b.printNums();

    std::cout << "\nTest 3: exception" << std::endl;
    try
    {
        b.addNumber(4);
    }
    catch (const std::exception &e)
    {
        std::cerr << "value could not be added. " << e.what() << '\n';
    }

    std::cout << "\nTest 4: longest span" << std::endl;
    Span too_short(1);
    too_short.addNumber(66);
    try
    {
        std::cout << "The longest span is " << b.longestSpan() << std::endl;
        unsigned int res = too_short.longestSpan();
        std::cout << "The longest span is " << res << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Span could not be calculated. " << e.what() << '\n';
    }

    std::cout << "\nTest 5: shortest span" << std::endl;
    Span short_span(5);
    short_span.addNumber(INT_MIN);
    short_span.addNumber(INT_MAX);
    // short_span.addNumber(0);
    // short_span.printNums();
    std::cout << "The shortest span is " << short_span.shortestSpan() << std::endl;
    try
    {
        //std::cout << "The longest span is " << short_span.longestSpan() << std::endl;
        unsigned int res = too_short.shortestSpan();
        std::cout << "The shortest span is " << res << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Span could not be calculated. " << e.what() << '\n';
    }

    std::cout << "\nTest 6: from subject" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\nTest 7: addMultipleNumbers" << std::endl;

    std::vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i * 10);
    Span ss(5);
    ss.addMultipleNumbers(v.begin(), v.end());
    ss.printNums(); // expect 0 10 20 30 40

    std::cout << "\nTest 8: 20000 numbers, check how long it takes" << std::endl;
    {
        // std::list<int> v;
        std::vector<int> v;
        size_t _size_1 = 20000;
        size_t _size_2 = 2;
        for (size_t i = 0; i < _size_1; i++)
            v.push_back(i * 3); // sorted gaps are all 3
        std::random_shuffle(v.begin(), v.end());
        Span sp(_size_1 + _size_2);
        clock_t t = clock();
        sp.addMultipleNumbers(v.begin(), v.end());
        std::list<int> li;
        li.push_back(60000);
        li.push_back(60003);
        sp.addMultipleNumbers(li.begin(), li.end());
        std::cout << "shortest: " << sp.shortestSpan() << " (expect 3)" << std::endl;
        std::cout << "longest:  " << sp.longestSpan() << " (expect " << 3 * 19999 + 6 << ")" << std::endl;
        std::cout << "time: " << (double(clock() - t) / CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
    }
}
