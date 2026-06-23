/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:05:59 by slambert          #+#    #+#             */
/*   Updated: 2026/06/23 11:30:02 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap Name constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != & other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints < 1 || _energyPoints < 1)
    {
        std::cout << "attack function exited early" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (_hitPoints < 1 || _energyPoints < 1)
    {
        std::cout << "guardGate function exited early" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
