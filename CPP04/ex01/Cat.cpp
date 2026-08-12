/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:33:37 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 11:40:23 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat &other): Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain (*other._brain);
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete(_brain);
        _brain = new Brain (*other._brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout <<  "Cat Destructor called" << std::endl;
    delete(_brain);
}

void Cat::makeSound() const
{
    std::cout <<  "Cat sounds" << std::endl;
}

Brain* Cat::getBrain() const
{
    return _brain;
}
