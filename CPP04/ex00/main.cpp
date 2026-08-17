/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:25 by slambert          #+#    #+#             */
/*   Updated: 2026/08/17 16:35:11 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // cat sound
	j->makeSound();
	meta->makeSound();
    
    delete(meta);
    delete(j);
    delete(i);
    
    std::cout << std::endl;
    //in WrongAnimal makeSound is not virtual
    const WrongAnimal	*wa = new WrongCat();
    wa->makeSound();
    delete(wa);
    
    std::cout << std::endl;
    Dog d1;
    std::cout << std::endl;
    Dog d2(d1);
    std::cout << std::endl;
    Dog d3;
    std::cout << std::endl;
    d3 = d1;

    std::cout << d2.getType() << std::endl;
    std::cout << d3.getType() << std::endl;
	return (0);
}
