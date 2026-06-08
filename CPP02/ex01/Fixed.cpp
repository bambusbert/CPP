/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:35:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/08 16:58:59 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num): num(num << fract_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

//copy constructor.
//gets called on Fixed a = b or Fixed A (B);
Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    this->num = f.getRawBits();
}

//copy assignment operator
//gets called on A=B (while A already exists)
Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        this->num = f.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->num;
}

void Fixed::setRawBits( int const raw )
{
    this->num = raw;
}