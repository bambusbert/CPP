/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:05:13 by slambert          #+#    #+#             */
/*   Updated: 2026/09/29 14:36:24 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T> void iter(T* arr, const size_t size, void (*fp)(T& arg))
{
	for (size_t i = 0; i < size; i++)
		fp(arr[i]);
}

template <typename T> void iter(const T* arr, const size_t size, void (*fp)(const T& arg))
{
	for (size_t i = 0; i < size; i++)
		fp(arr[i]);
}

// this solution is anarchy but would be valid also
// template <typename T, typename F> void iter(T* arr, const size_t size, F fp)
// {
// 	for (size_t i = 0; i < size; i++)
// 		fp(arr[i]);
// }
#endif
