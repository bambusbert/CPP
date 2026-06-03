/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:42:13 by slambert          #+#    #+#             */
/*   Updated: 2026/06/03 19:02:58 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main (void)
{
    Zombie *pZ;
    
    randomChump("ChumpZombert");
    pZ = newZombie("PointerZombert");
    pZ->announce();
    delete(pZ);
}
