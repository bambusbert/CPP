/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:40:46 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 12:42:57 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(const AMateria &other);
        AMateria& operator=(const AMateria &other);
        virtual ~AMateria();
        AMateria(std::string const &type);
         
        std::string const &getType() const; // Returns the materia type
        
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
    
};

#endif
