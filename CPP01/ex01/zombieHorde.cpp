/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:04:35 by slambert          #+#    #+#             */
/*   Updated: 2026/06/03 19:09:20 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *pZ = new Zombie[N];
    
    for (int i = 0; i < N; i++)
    {
        pZ[i].setName(name);
    }
    return pZ;
}