/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:25 by slambert          #+#    #+#             */
/*   Updated: 2026/06/22 17:38:17 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
    std::string name = "Herbert";
    ScavTrap a(name);
    a.attack("manfred");
    a.takeDamage(5);
    a.beRepaired(6);
    a.takeDamage(255);
    a.attack("asdf");
}
