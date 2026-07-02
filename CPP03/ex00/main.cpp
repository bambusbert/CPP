/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:25 by slambert          #+#    #+#             */
/*   Updated: 2026/07/02 15:50:43 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
    //std::string name = "Herbert";
    ClapTrap a("Herbert");
    a.attack("manfred");
    a.takeDamage(5);
    a.beRepaired(6);
    a.takeDamage(255);
    a.takeDamage(1);
    a.attack("asdf");
    std::cout << std::endl;
    
    ClapTrap b;
    b.attack("adss");
}
