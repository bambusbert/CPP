/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:29:20 by slambert          #+#    #+#             */
/*   Updated: 2026/06/12 11:15:00 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//we have to do this because _x and _y are const and C++ demands that we 
//specifically construct these members in the constructor list
Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::~Point() {}

//copy constructor, internally just calling the =operator to not have code twice
Point::Point(const Point& p): _x(p._x), _y(p._y) {}

//that is completely useless bc _x and _y are const so we can't change them
//however, we need it because the subject states so
Point& Point::operator=(const Point& p)
{
    (void) p;
    return *this;
}