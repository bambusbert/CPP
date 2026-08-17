/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:34:12 by slambert          #+#    #+#             */
/*   Updated: 2026/08/17 17:31:27 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain* _brain;  
    public:
        Cat();
        Cat(const Cat &other);
        Cat& operator=(const Cat &other);
        virtual ~Cat();
        virtual void makeSound() const;
        Brain* getBrain() const;
};

#endif
