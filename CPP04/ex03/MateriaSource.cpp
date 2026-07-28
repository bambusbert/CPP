/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:57:43 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 14:51:59 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void MateriaSource::empty_materias()
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
}

//delete NULL i OK so no protection needed
void MateriaSource::free_materias()
{
    for (int i = 0; i < 4; i++)
    {
        delete this->_materias[i];
        this->_materias[i] = NULL;
    }
}

void MateriaSource::clone_materias(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        this->_materias[i] = other._materias[i]->clone(); 
    }
}

MateriaSource::MateriaSource()
{
    empty_materias();
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    clone_materias(other);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        free_materias();
        clone_materias(other);
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    free_materias();
}

void MateriaSource::learnMateria(AMateria *materia)
{
    int i = 0;
    
    while (this->_materias[i])
    {
        i++;
        if (i >= 4)
        {
            delete materia;
            return ;
        }
    }
    this->_materias[i] = materia->clone();
    delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int i = 0;

    while (i < 4)
    {
        if (_materias[i]->getType() == type)
            return _materias[i]->clone();
        i++;
    }
    return 0;
}
