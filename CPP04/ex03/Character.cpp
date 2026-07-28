/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:59:22 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 12:25:36 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void Character::empty_inv()
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(): _name("anon")
{
    empty_inv();
}

Character::Character(const Character &other): _name(other._name)
{
    empty_inv();
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        //copy inventory
        //this is a SHALLOW COPY
        for (int i = 0; i < 4; i++)
            this->_inventory[i] = other._inventory[i];
    }
    return *this;
}

Character::~Character()
{
    
}

std::string const &Character::getName() const
{
    return this->_name;
}

void	Character::equip(AMateria *m)
{
    int i = 0;
    
    while (this->_inventory[i])
    {
        i++;
        if (i >= 4)
            return ;
    }
    this->_inventory[i] = m;
}

void	Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return ;
    this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4)
        return ;
    this->_inventory[idx]->use(target);    
}
