/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:35:49 by slambert          #+#    #+#             */
/*   Updated: 2026/06/12 10:20:29 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructor
Fixed::Fixed() : _val(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

// int constructor. no precision is lost
Fixed::Fixed(const int val)
{
    //std::cout << "Int constructor called" << std::endl;
    _val = val << _fract_bits;
}

// float constructor. precision is lost
// we can't bit shift a float. therefore we do the equivalant (multiplication)
//(multiplication with 256 is 1 left-shifted by _fract_bits bits)
Fixed::Fixed(const float val)
{
    //std::cout << "Float constructor called" << std::endl;
    _val = static_cast<int>(roundf(val * (1 << _fract_bits)));
}

// copy constructor.
// gets called on Fixed a = b or Fixed A (B);
//(for exact output like in the subject we call the copy assignment operator here)
Fixed::Fixed(const Fixed &f)
{
    //std::cout << "Copy constructor called" << std::endl;
    // this->_val = f.getRawBits();
    *this = f;
}

// copy assignment operator
// gets called on A=B (while A already exists)
Fixed &Fixed::operator=(const Fixed &f)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        this->_val = f.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_val;
}

void Fixed::setRawBits(int const raw)
{
    this->_val = raw;
}

// divide by 2^_fract_bits and return that
float Fixed::toFloat(void) const
{
    return static_cast<float>(_val) / (1 << _fract_bits);
}

// we return truncated int (right shift by _fract_bits bits)
int Fixed::toInt(void) const
{
    return _val >> _fract_bits;
}

// overload the << operator to output the floating point representation
// given to output stream
std::ostream &operator<<(std::ostream &stream, const Fixed &f)
{
    stream << f.toFloat();
    return stream;
}

// ex02
bool Fixed::operator<(const Fixed &other) const
{
    return this->_val < other._val;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->_val > other._val;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_val <= other._val;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_val >= other._val;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_val == other._val;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_val != other._val;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;

    res.setRawBits(this->_val + other._val);
    return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;

    res.setRawBits(this->_val - other._val);
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;

    long long temp = (long long)this->_val * other._val;
    res.setRawBits(temp >> _fract_bits);
    return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed res;

    long long temp = ((long long)this->_val << _fract_bits) / other._val;
    res.setRawBits(temp);
    return res;
}

// pre-increment
Fixed &Fixed::operator++(void)
{
    _val++;
    return *this;
}

Fixed &Fixed::operator--(void)
{
    _val--;
    return *this;
}

// post-increment
// Saves the current state, increments the raw value, and returns the old state.
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _val++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _val--;
    return temp;
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
    return n1._val < n2._val ? n1 : n2;
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
    return n1._val > n2._val ? n1 : n2;
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2)
{
    return n1._val < n2._val ? n1 : n2;
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2)
{
    return n1._val > n2._val ? n1 : n2;
}