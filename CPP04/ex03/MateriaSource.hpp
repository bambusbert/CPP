/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:57:37 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 14:41:46 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

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
        ~MateriaSource();
        
        void learnMateria(AMateria * materia);
        AMateria *createMateria(std::string const &type);
};

#endif
