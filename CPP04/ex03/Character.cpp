/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:59:22 by slambert          #+#    #+#             */
/*   Updated: 2026/07/29 11:25:44 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void Character::empty_inv()
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

//delete NULL i OK so no protection needed
void Character::free_inv()
{
    for (int i = 0; i < 4; i++)
    {
        delete this->_inventory[i];
        this->_inventory[i] = NULL;
    }
}

//this is a NOT A SHALLOW COPY
void Character::clone_inv(const Character &other)
{
    for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = other._inventory[i]->clone(); 
    }
}

Character::Character(): _name("anon")
{
    empty_inv();
}

Character::Character(const std::string name): _name(name)
{
    empty_inv();
}

Character::Character(const Character &other): _name(other._name)
{
    clone_inv(other);
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        free_inv();
        clone_inv(other);
    }
    return *this;
}

Character::~Character()
{
    free_inv();
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
    if (idx < 0 || idx >= 4 || !this->_inventory[idx])
        return ;
    this->_inventory[idx]->use(target);
}
