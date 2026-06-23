/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:32:20 by slambert          #+#    #+#             */
/*   Updated: 2026/06/23 15:56:06 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{

}

Animal::Animal(const std::string &type)
{

}

Animal::Animal(const Animal &other)
{
    
}

Animal& Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        
    }
    return *this;
}

Animal::~Animal()
{
    std::cout <<  "Animal Destructor called" << std::endl;
}