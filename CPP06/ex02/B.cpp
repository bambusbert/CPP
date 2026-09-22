/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:27:12 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 14:10:01 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::~B()
{
    
}

void B::identify (Base *p)
{
    (void)p;
    std::cout << "B" << std::endl;
}

void B::identify (Base &p)
{
    (void)p;
    std::cout << "B" << std::endl;
}
