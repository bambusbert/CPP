/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:40:24 by slambert          #+#    #+#             */
/*   Updated: 2026/07/23 16:46:55 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    
}

AMateria::AMateria(std::string const &type)
{
    this->_type = type;
}

AMateria::AMateria(const AMateria &other)
{
    this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

AMateria::~AMateria()
{
    
}

std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter &target)
{
    //???
}
