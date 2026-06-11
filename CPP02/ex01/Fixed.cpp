/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:35:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/11 12:57:45 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//default constructor
Fixed::Fixed(): _val(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//int constructor. no precision is lost
Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
    _val = val << _fract_bits;
}

//float constructor. precision is lost
//we can't bit shift a float. therefore we do the equivalant (multiplication)
//(multiplication with 256 is 1 left-shifted by _fract_bits bits)
Fixed::Fixed(const float val)
{
    std::cout << "Float constructor called" << std::endl;
    _val = static_cast<int>(roundf(val * (1 << _fract_bits)));
}

//copy constructor.
//gets called on Fixed a = b or Fixed A (B);
//(for exact output like in the subject we call the copy assignment operator here)
Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    //this->_val = f.getRawBits();
    *this = f;
}

//copy assignment operator
//gets called on A=B (while A already exists)
Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        this->_val = f.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_val;
}

void Fixed::setRawBits( int const raw )
{
    this->_val = raw;
}

//divide by 2^_fract_bits and return that
float Fixed::toFloat( void ) const
{
    return static_cast<float>(_val) / (1 << _fract_bits);
}

//we return truncated int (right shift by _fract_bits bits)
int Fixed::toInt( void ) const
{
    return _val >> _fract_bits;
}

//overload the << operator to output the floating point representation
//given to output stream
std::ostream& operator<<(std::ostream& stream, const Fixed& f)
{
    stream << f.toFloat();
    return stream;
}