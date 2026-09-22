/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:25:26 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 14:10:31 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    
}

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

//if you wanna use this function you have to seed in main
Base* Base::generate(void)
{
    Base*(*function_ptr[3])() = {&generateA, &generateB, &generateC};
    int i = rand() % 3;
    return function_ptr[i]();
}

void Base::identify(Base *p)
{
    p->identify(p);
}

void Base::identify(Base &p)
{
    p.identify(p);
}
