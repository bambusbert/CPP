/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:04:49 by slambert          #+#    #+#             */
/*   Updated: 2026/10/06 15:42:01 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO
- better tests
- algorithm solution for shortestSpan
- method to add multiple numbers at once */

#include "Span.hpp"
#include <iostream>
#include <climits>

int main(void)
{
    std::cout << "Test 0: number constructor" << std::endl;
    Span s(3);
    s.addNumber(1);
    s.addNumber(2);
    s.addNumber(3);
    s.printNums();

    std::cout << "\nTest 1: copy constructor" << std::endl;
    Span copy(s);
    copy.printNums();

    std::cout << "\nTest 2: copy assignment operator" << std::endl;
    Span b(3);
    b.addNumber(10);
    b.addNumber(20);
    b.addNumber(30);
    b = s;
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
        std::cout << "The longest span is " << too_short.longestSpan() << std::endl;
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
    try
    {
        std::cout << "The shortest span is " << short_span.shortestSpan() << std::endl;
        // std::cout << "The longest span is " << short_span.longestSpan() << std::endl;
        std::cout << "The shortest span is " << too_short.shortestSpan() << std::endl;
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

    std::cout << "\nTest 13: 20000 numbers, check how long it takes" << std::endl;
    {
        std::vector<int> v;
        for (int i = 0; i < 20000; i++)
            v.push_back(i * 3); // sorted gaps are all 3
        std::random_shuffle(v.begin(), v.end());
        Span sp(20000);
        clock_t t = clock();
        sp.addMultipleNumbers(v.begin(), v.end());
        std::cout << "shortest: " << sp.shortestSpan() << " (expect 3)" << std::endl;
        std::cout << "longest:  " << sp.longestSpan() << " (expect " << 3 * 19999 << ")" << std::endl;
        std::cout << "time: " << double(clock() - t) / CLOCKS_PER_SEC << "s" << std::endl;
    }
}
