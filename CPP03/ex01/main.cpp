/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:25 by slambert          #+#    #+#             */
/*   Updated: 2026/07/06 13:37:14 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("Herbert");
	a.attack("manfred");
	a.takeDamage(5);
	a.beRepaired(6);
	a.guardGate();
	a.takeDamage(255);
	a.attack("asdf");
	a.guardGate();
	std::cout << std::endl;

	ScavTrap c("Original");

	ScavTrap d(c);
	d.attack("clone target");
	std::cout << std::endl;

	ScavTrap e("Temp");
	e = c;
	e.attack("assigned target");
	std::cout << std::endl;

	ScavTrap f("TiredRobot");
	for (int i = 0; i < 51; i++) {
		f.attack("a training dummy");
	}
	f.guardGate(); // Should fail because energy is 0
	
	std::cout << std::endl;
	return 0;
}
