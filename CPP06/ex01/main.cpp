/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:30:46 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 12:23:19 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d;
    d.x = 6;
    d.y = 7;

    uintptr_t tmp_ptr = Serializer::serialize(&d);
    Data* d2 = Serializer::deserialize(tmp_ptr);
    
    std::cout << "TEST1" << std::endl;
    std::cout << "x: " << d2->x << std::endl;
    std::cout << "y: " << d2->y << std::endl;

    std::cout << "\nTEST2" << std::endl;
    std::cout << &d << std::endl;
    std::cout << d2 << std::endl;
}
