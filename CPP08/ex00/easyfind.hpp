/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:45:19 by slambert          #+#    #+#             */
/*   Updated: 2026/10/06 11:52:04 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>

template <typename T>
typename T::iterator easyfind(T& con, int num)
{
    return std::find(con.begin(), con.end(), num);
}

template <typename T>
typename T::const_iterator easyfind(const T& con, int num)
{
    return std::find(con.begin(), con.end(), num);
}

//that's without algorithm
// template <typename T>
// typename T::iterator easyfind(T& con, int num)
// {
//     typename T::iterator it;
//     for (it = con.begin(); it != con.end(); ++it)
//     {
//         if (*it == num)
//             return it;
//     }
//     return con.end();
// }

//#include "easyfind.tpp"

#endif
