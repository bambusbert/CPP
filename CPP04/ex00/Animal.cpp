/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:32:20 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 11:19:37 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other): _type(other._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

const std::string& Animal::getType() const
{
    return _type;
}

Animal::~Animal()
{
    std::cout <<  "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout <<  "Animal sounds" << std::endl;
}
