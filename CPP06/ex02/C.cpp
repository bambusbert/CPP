/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:27:12 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 14:10:05 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::~C()
{
    
}

void C::identify (Base *p)
{
    (void)p;
    std::cout << "C" << std::endl;
}

void C::identify (Base &p)
{
    (void)p;
    std::cout << "C" << std::endl;
}
