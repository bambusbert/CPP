/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:42:13 by slambert          #+#    #+#             */
/*   Updated: 2026/06/15 12:09:33 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#include <iostream>
#include "Point.hpp"

// Forward declaration of the bsp function
bool bsp( Point const a, Point const b, Point const c, Point const point);

// A small helper function to keep the main output clean and readable
void runTest(std::string testName, Point a, Point b, Point c, Point p, bool expected)
{
    bool result = bsp(a, b, c, p);
    
    std::cout << "--- " << testName << " ---" << std::endl;
    std::cout << "Result:   " << (result ? "Inside (True)" : "Outside/Edge (False)") << std::endl;
    std::cout << "Expected: " << (expected ? "Inside (True)" : "Outside/Edge (False)") << std::endl;
    
    if (result == expected)
        std::cout << "[PASS] \n" << std::endl;
    else
        std::cout << "[FAIL] \n" << std::endl;
}

int main( void )
{
    std::cout << "========== BSP ALGORITHM TESTS ==========\n" << std::endl;

    // -------------------------------------------------------------------------
    // TRIANGLE 1: A standard right-angle triangle
    // Vertices at (0,0), (10,0), and (0,10)
    // -------------------------------------------------------------------------
    Point a1(0.0f, 0.0f);
    Point b1(10.0f, 0.0f);
    Point c1(0.0f, 10.0f);

    std::cout << ">> Testing Standard Right Triangle (0,0), (10,0), (0,10)\n" << std::endl;

    // 1. Clearly Inside
    runTest("Test 1: Point strictly inside (2, 2)", 
            a1, b1, c1, Point(2.0f, 2.0f), true);

    // 2. Clearly Outside
    runTest("Test 2: Point completely outside (10, 10)", 
            a1, b1, c1, Point(10.0f, 10.0f), false);

    // 3. The Edge Case (Must return false per subject rules)
    runTest("Test 3: Point exactly on edge A->B (5, 0)", 
            a1, b1, c1, Point(5.0f, 0.0f), false);

    // 4. The Hypotenuse Case
    runTest("Test 4: Point exactly on hypotenuse B->C (5, 5)", 
            a1, b1, c1, Point(5.0f, 5.0f), false);

    // 5. The Vertex Case
    runTest("Test 5: Point exactly on Vertex A (0, 0)", 
            a1, b1, c1, Point(0.0f, 0.0f), false);


    // -------------------------------------------------------------------------
    // TRIANGLE 2: Negative Coordinates & Winding
    // Vertices at (-5,-5), (5,-5), and (0,5)
    // -------------------------------------------------------------------------
    Point a2(-5.0f, -5.0f);
    Point b2(5.0f, -5.0f);
    Point c2(0.0f, 5.0f);

    std::cout << ">> Testing Negative Coordinates (-5,-5), (5,-5), (0,5)\n" << std::endl;

    // 6. Inside with negatives
    runTest("Test 6: Inside the negative coordinate space (0, 0)", 
            a2, b2, c2, Point(0.0f, 0.0f), true);

    // 7. Outside below the triangle
    runTest("Test 7: Outside, directly below the triangle (0, -6)", 
            a2, b2, c2, Point(0.0f, -6.0f), false);

    return 0;
}