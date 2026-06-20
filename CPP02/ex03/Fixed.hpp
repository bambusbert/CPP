/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:36:02 by slambert          #+#    #+#             */
/*   Updated: 2026/06/20 13:03:07 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _val;
		static const int _fract_bits = 8;
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& f);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		//pre-increment
		Fixed& operator++(void);
		Fixed& operator--(void);
		//post-increment
		Fixed operator++ (int);
		Fixed operator-- (int);
		static Fixed& min(Fixed &n1, Fixed& n2);
		static Fixed& max(Fixed &n1, Fixed& n2);
		static const Fixed& min(const Fixed &n1, const Fixed& n2);
		static const Fixed& max(const Fixed &n1, const Fixed& n2);
};

std::ostream& operator<<(std::ostream& stream, const Fixed& f);

#endif