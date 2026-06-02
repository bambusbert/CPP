/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:42:37 by slambert          #+#    #+#             */
/*   Updated: 2026/06/02 12:07:07 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

const std::string Zombie::getName() const
{
    return name;
}

void Zombie::announce (void)
{
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

