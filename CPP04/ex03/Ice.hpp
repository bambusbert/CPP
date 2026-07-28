/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:59:47 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 14:44:09 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& other);
        const Ice& operator=(const Ice& other);
        ~Ice();

        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif
