/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:57:37 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 17:08:51 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materias[4];
        void empty_materias();
        void free_materias();
        void clone_materias(const MateriaSource &other);
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        virtual ~MateriaSource();
        virtual void learnMateria(AMateria * materia);
        virtual AMateria *createMateria(std::string const &type);
};

#endif
