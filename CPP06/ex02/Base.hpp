/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:25:20 by slambert          #+#    #+#             */
/*   Updated: 2026/09/22 14:02:39 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base
{
    private:

    public:
        virtual ~Base();
        Base* generate(void);
        virtual void identify(Base *p);
        virtual void identify(Base& p);
};

#endif
