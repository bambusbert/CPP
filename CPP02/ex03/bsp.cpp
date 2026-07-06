/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:28:12 by slambert          #+#    #+#             */
/*   Updated: 2026/07/06 12:37:01 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// returns > 0 if p is to the left of the line a->b.
// returns < 0 if p is to the right of the line a->b
// returns 0 if p is on the line
static Fixed crossProduct(Point const a, Point const b, Point const p)
{
    return ((b.getX() - a.getX()) * (p.getY() - a.getY())) - 
           ((b.getY() - a.getY()) * (p.getX() - a.getX()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed check1 = crossProduct(a, b, point);
    Fixed check2 = crossProduct(b, c, point);
    Fixed check3 = crossProduct(c, a, point);

    if (check1 == Fixed(0) || check2 == Fixed(0) || check3 == Fixed(0))
        return false;

    bool allPositive = (check1 > Fixed(0) && check2 > Fixed(0) && check3 > Fixed(0));
    bool allNegative = (check1 < Fixed(0) && check2 < Fixed(0) && check3 < Fixed(0));

    return (allPositive || allNegative);
}