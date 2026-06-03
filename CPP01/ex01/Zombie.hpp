/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:42:23 by slambert          #+#    #+#             */
/*   Updated: 2026/06/03 19:08:35 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "iostream"

class Zombie
{
    private:
        std::string name;

    public:
        const std::string getName() const;
        void setName(std::string name);
        void announce (void);
        Zombie();
        Zombie(std::string name);
        ~Zombie();
};

#endif