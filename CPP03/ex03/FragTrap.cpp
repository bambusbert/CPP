/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:36:19 by slambert          #+#    #+#             */
/*   Updated: 2026/07/06 12:57:11 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "FragTrap Default constructor called" << std::endl;
    _hitPoints = 100;
    _defaultHitPoints = 100;
    _energyPoints = 100;
    _defaultEnergyPoints = 100;
    _attackDamage = 30;
    _defaultAttackDamage = 30;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
    std::cout << "FragTrap Name constructor called" << std::endl;
    _hitPoints = 100;
    _defaultHitPoints = 100;
    _energyPoints = 100;
    _defaultEnergyPoints = 100;
    _attackDamage = 30;
    _defaultAttackDamage = 30;
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
    if (_hitPoints < 1 || _energyPoints < 1)
    {
        std::cout << "FragTrap " << _name << " can't high five" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " is kindly requesting a high five." << std::endl;
}
