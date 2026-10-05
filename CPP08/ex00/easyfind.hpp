/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:45:19 by slambert          #+#    #+#             */
/*   Updated: 2026/10/05 18:38:26 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>

//returns -1 if not found
template <typename T>
typename T::iterator easyfind(T& con, int num)
{
    typename T::iterator it;
    for (it = con.begin(); it != con.end(); ++it)
    {
        if (*it == num)
            return it;
    }
    return con.end();
}

//#include "easyfind.tpp"

#endif
