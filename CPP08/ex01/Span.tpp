/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:38:03 by slambert          #+#    #+#             */
/*   Updated: 2026/10/06 16:13:07 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"
#include <iterator>

template <typename T>
void Span::addMultipleNumbers(T first, T last)
{
    unsigned int needed_space = static_cast<unsigned int>(std::distance(first, last));
    if (nums.size() + needed_space > _N)
        throw SpanFullException();
    nums.insert(nums.end(), first, last);
}

#endif
