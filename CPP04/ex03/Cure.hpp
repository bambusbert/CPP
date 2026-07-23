/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:00:15 by slambert          #+#    #+#             */
/*   Updated: 2026/07/23 16:53:09 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : AMateria
{
    public:
        Cure();
        Cure(const Cure& other);
        const Cure& operator=(const Cure& other);
        ~Cure();
        
        AMateria *clone() const;
};

#endif
