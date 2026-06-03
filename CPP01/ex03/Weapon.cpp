/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:25:37 by slambert          #+#    #+#             */
/*   Updated: 2026/06/03 20:46:14 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

const std::string& Weapon::getType() const
{
    return (const std::string&)type;
}

void Weapon::setType(std::string type)
{
    this->type = type;   
}