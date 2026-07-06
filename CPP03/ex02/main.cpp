/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:25 by slambert          #+#    #+#             */
/*   Updated: 2026/07/06 13:39:55 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	// std::string name = "Herbert";
	ScavTrap a("Herbert");
	a.attack("manfred");
	a.takeDamage(5);
	a.beRepaired(6);
	a.guardGate();
	a.takeDamage(255);
	a.attack("asdf");
	a.guardGate();
	std::cout << std::endl;
	
	FragTrap b("Rudolf");
	b.attack("Herbert");
	b.takeDamage(22);
	b.beRepaired(1);
	b.highFivesGuys();
	b.takeDamage(333);
	b.attack("dd");
	b.highFivesGuys();
	std::cout << std::endl;

	FragTrap c("OriginalFrag");
	
	// Copy Constructor
	FragTrap d(c);
	d.highFivesGuys();
	std::cout << std::endl;

	// Copy Assignment Operator
	FragTrap e("TempFrag");
	e = c;
	e.highFivesGuys();
	std::cout << std::endl;

	return 0;
	
}
