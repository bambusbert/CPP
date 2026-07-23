/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:34:22 by slambert          #+#    #+#             */
/*   Updated: 2026/07/23 14:42:42 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete(_brain);
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout <<  "Dog Destructor called" << std::endl;
    delete(_brain);
}

void Dog::makeSound() const
{
    std::cout <<  "Dog sounds" << std::endl;
}

Brain* Dog::getBrain() const
{
    return _brain;
}
