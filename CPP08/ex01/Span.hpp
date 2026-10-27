/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:55:05 by slambert          #+#    #+#             */
/*   Updated: 2026/10/27 12:35:35 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Span
{
private:
    unsigned int _N;
    std::vector<int> _nums;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    void addNumber(int num);
    void printNums() const;
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    template <typename T>
    void addMultipleNumbers(T first, T last);

    class SpanFullException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class ZeroOrOneElementException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#include "Span.tpp"

#endif
