/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:48:12 by slambert          #+#    #+#             */
/*   Updated: 2026/07/02 16:15:13 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap(), _name("Anon")
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;
    //ClapTrap::_name = "Anon_clap_name";
    _hitPoints = FragTrap::_defaultHitPoints;
    _energyPoints = ScavTrap::_defaultEnergyPoints;
    _attackDamage = FragTrap::_defaultAttackPoints;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    std::cout << "DiamondTrap Name constructor called" << std::endl;
    _hitPoints = FragTrap::_defaultHitPoints;
    _energyPoints = ScavTrap::_defaultEnergyPoints;
    _attackDamage = FragTrap::_defaultAttackPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != & other)
    {
        //why dont we need that line
        //ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is " << _name << ". My ClapTrap name is " << ClapTrap::_name << std::endl;
}
