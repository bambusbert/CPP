/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:42:37 by slambert          #+#    #+#             */
/*   Updated: 2026/06/06 10:14:10 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->getName() << ": is dead" << std::endl;
}

const std::string Zombie::getName() const
{
    return name;
}

void Zombie::announce (void)
{
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}