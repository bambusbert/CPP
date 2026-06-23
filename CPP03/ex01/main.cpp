/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:25 by slambert          #+#    #+#             */
/*   Updated: 2026/06/23 11:26:53 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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
}
