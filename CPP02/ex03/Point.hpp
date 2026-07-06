/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:27:46 by slambert          #+#    #+#             */
/*   Updated: 2026/07/06 12:37:01 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;       
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& p);
        Point& operator=(const Point& p);
        ~Point();
        Fixed getX( void ) const;
        Fixed getY( void ) const;
};

#endif