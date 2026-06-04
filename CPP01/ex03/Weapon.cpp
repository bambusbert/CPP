/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:25:37 by slambert          #+#    #+#             */
/*   Updated: 2026/06/04 11:04:53 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    this->type = name;
}

const std::string& Weapon::getType() const
{
    return (const std::string&)type;
}

void Weapon::setType(std::string type)
{
    this->type = type;   
}