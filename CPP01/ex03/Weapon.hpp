/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:24:52 by slambert          #+#    #+#             */
/*   Updated: 2026/06/03 20:46:53 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon();
        const std::string& getType() const;
        void setType(std::string type);
};

#endif