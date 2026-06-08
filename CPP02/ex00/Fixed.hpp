/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:36:02 by slambert          #+#    #+#             */
/*   Updated: 2026/06/08 15:59:09 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		unsigned int num;
		static const int fract_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& f);
		Fixed &operator=(const Fixed& f);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif