/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:17:27 by slambert          #+#    #+#             */
/*   Updated: 2026/07/23 15:17:33 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other): _type(other._type)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

const std::string& AAnimal::getType() const
{
    return _type;
}

AAnimal::~AAnimal()
{
    std::cout <<  "AAnimal Destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
    std::cout <<  "AAnimal sounds" << std::endl;
}
