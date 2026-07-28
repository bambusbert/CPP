/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:59:47 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 12:36:32 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Ice : AMateria
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
