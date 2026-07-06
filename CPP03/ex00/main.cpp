/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:25 by slambert          #+#    #+#             */
/*   Updated: 2026/07/06 13:35:23 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap a("Herbert");
    a.attack("manfred");
    a.takeDamage(5);
    a.beRepaired(6);
    a.takeDamage(255);
    a.takeDamage(1);
    a.attack("asdf");
    std::cout << std::endl;
    
    ClapTrap b("EnergyTester");
    b.attack("target 1"); // 9 energy left
    b.attack("target 2"); // 8
    b.attack("target 3"); // 7
    b.attack("target 4"); // 6
    b.attack("target 5"); // 5
    b.attack("target 6"); // 4
    b.attack("target 7"); // 3
    b.attack("target 8"); // 2
    b.attack("target 9"); // 1
    b.beRepaired(1);      // 0 energy left
    b.attack("target 11"); // Should fail due to 0 EP
    b.beRepaired(1);       // same
    std::cout << std::endl;

    ClapTrap c("Original");
    
    // Copy Constructor
    ClapTrap d(c);
    d.attack("clone target");
    std::cout << std::endl;

    // Copy Assignment Operator
    ClapTrap e;
    e = c;
    e.attack("assigned target");
    std::cout << std::endl;
    
    return 0;
}
