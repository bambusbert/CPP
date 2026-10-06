/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:55:11 by slambert          #+#    #+#             */
/*   Updated: 2026/10/06 15:42:19 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
    nums.reserve(_N);
}

Span::Span(const Span &other) : _N(other._N), nums(other.nums)
{
    nums.reserve(_N);
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        nums = other.nums;
        nums.reserve(_N);
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
    if (nums.size() >= _N)
        throw SpanFullException();
    nums.push_back(num);
}

void Span::printNums() const
{
    for (unsigned int i = 0; i < nums.size(); i++)
        std::cout << nums[i] << std::endl;
}

long Span::shortestSpan() const
{
    if (nums.size() <= 1)
        throw ZeroOrOneElementException();
    std::vector<long>v;
    v.reserve(nums.size());
    v.insert(v.end(), nums.begin(), nums.end());
    std::sort(v.begin(), v.end());
    std::adjacent_difference(v.begin(), v.end(), v.begin());
    long shortest_dist = *(std::min_element(v.begin() + 1, v.end()));
    return shortest_dist;
}

//stupid solution without algorithm
/* static long calc_delta(int num1, int num2)
{
    if (num2 < num1)
        std::swap(num1, num2);
    return std::abs(static_cast<long>(num2) - static_cast<long>(num1));
}

#include <climits>
long Span::shortestSpan() const
{
    if (nums.size() <= 1)
        throw ZeroOrOneElementException();
    long delta = LONG_MAX;
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums.size(); j++)
        {
            if (i == j)
                continue;
            long delta_to_check = calc_delta(nums[i], nums[j]);
            if (delta_to_check < delta)
                delta = delta_to_check;
        }
    }
    return delta;
} */

long Span::longestSpan() const
{
    if (nums.size() <= 1)
        throw ZeroOrOneElementException();
    int max = *(std::max_element(nums.begin(), nums.end()));
    int min = *(std::min_element(nums.begin(), nums.end()));
    return static_cast<long>(max) - min;
}

const char *Span::SpanFullException::what() const throw()
{
    return "Span already full";
}

const char *Span::ZeroOrOneElementException::what() const throw()
{
    return "Span has zero or one elements";
}
