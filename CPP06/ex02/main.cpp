/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:30:46 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 17:23:35 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base* generateA()
{
    return new A();
}

static Base* generateB()
{
    return new B();
}

static Base* generateC()
{
    return new C();
}

static Base* generate(void)
{
    Base*(*function_ptr[3])() = {&generateA, &generateB, &generateC};
    int i = rand() % 3;
    return function_ptr[i]();
}

static void identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "neither A, B or C" << std::endl;
}

static void identify(Base &p)
{
    bool success = false;
    try
    {
        A& tmp = dynamic_cast<A&>(p);
        (void)tmp;
        success = true;
        std::cout << "A" << std::endl;
    }
    catch(std::exception &e){}
    try
    {
        B& tmp = dynamic_cast<B&>(p);
        (void)tmp;
        success = true;
        std::cout << "B" << std::endl;
    }
    catch(std::exception &e){}
    try
    {
        C& tmp = dynamic_cast<C&>(p);
        (void)tmp;
        success = true;
        std::cout << "C" << std::endl;
    }
    catch(std::exception &e){}
    if (!success)
    std::cout << "neither A, B or C" << std::endl;
}

int main()
{
    srand(std::time(NULL));
    Base* ptrs[10];
    for (int i = 0; i < 10; i++)
    {
        ptrs[i] = generate();
        std::cout << "Pointer " << i << ":" << std::endl;
        identify(ptrs[i]);
        identify(*(ptrs[i]));
        delete(ptrs[i]);
    }
}
