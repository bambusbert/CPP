/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:25 by slambert          #+#    #+#             */
/*   Updated: 2026/07/06 13:27:34 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	// std::string name = "Herbert";
	// ScavTrap a("Herbert");
	// a.attack("manfred");
	// a.takeDamage(5);
	// a.beRepaired(6);
	// a.guardGate();
	// a.takeDamage(255);
	// a.attack("asdf");
	// a.guardGate();
	// std::cout << std::endl;
	 
	// FragTrap b("Rudolf");
	// b.attack("Herbert");
	// b.takeDamage(22);
	// b.beRepaired(1);
	// b.highFivesGuys();
	// std::cout << std::endl;
	
	DiamondTrap c("BLING");
	// c.whoAmI();
	// c.attack("deine mama");
	// c.beRepaired(3);
	// c.takeDamage(22);
	// c.highFivesGuys();
	// c.guardGate();
	// c.takeDamage(444);
	// c.takeDamage(444);
	// std::cout << std::endl;
	
	// DiamondTrap d;
	// d.whoAmI();

	// Copy Constructor
	DiamondTrap e(c);
	e.whoAmI();
	e.attack("ein anderer typ");
	std::cout << std::endl;

	// Copy Assignment Operator
	DiamondTrap f("GÜNTHER");
	f.whoAmI();
	f = c;
	f.whoAmI();
	std::cout << std::endl;
	
}
