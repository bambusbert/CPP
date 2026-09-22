/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:27:12 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 14:09:57 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::~A()
{
    
}

void A::identify (Base *p)
{
    (void)p;
    std::cout << "A" << std::endl;
}

void A::identify (Base &p)
{
    (void)p;
    std::cout << "A" << std::endl;
}
