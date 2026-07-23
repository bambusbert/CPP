/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:57:43 by slambert          #+#    #+#             */
/*   Updated: 2026/07/23 17:03:47 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _known_materias(0)
{
    
}

MateriaSource::MateriaSource(const MateriaSource &other)
{

}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        
    }
}

MateriaSource::~MateriaSource()
{

}

void MateriaSource::learnMateria(AMateria *materia)
{
    
}

AMateria *MateriaSource::createMateria(std::string const &type)
{

}
