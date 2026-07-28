/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:00:26 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 13:41:17 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::Cure(const Cure &other): AMateria(other)
{
}

const Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " + target.getName() + " wounds *" << std::endl;
}
