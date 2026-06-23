/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:06:04 by slambert          #+#    #+#             */
/*   Updated: 2026/06/23 15:08:38 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        virtual ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
    protected:
        static const int _defaultHitPoints = 100;
        static const int _defaultEnergyPoints = 50;
        static const int _defaultAttackPoints = 20;
};

#endif
