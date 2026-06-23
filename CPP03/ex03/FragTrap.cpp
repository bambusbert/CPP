/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:36:19 by slambert          #+#    #+#             */
/*   Updated: 2026/06/23 12:26:20 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "FragTrap Default constructor called" << std::endl;
    _hitPoints = _defaultHitPoints;
    _energyPoints = _defaultEnergyPoints;
    _attackDamage = _defaultAttackPoints;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
    std::cout << "FragTrap Name constructor called" << std::endl;
    _hitPoints = _defaultHitPoints;
    _energyPoints = _defaultEnergyPoints;
    _attackDamage = _defaultAttackPoints;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != & other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " is kindly requesting a high five." << std::endl;
}
