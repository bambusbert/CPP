/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:21:25 by slambert          #+#    #+#             */
/*   Updated: 2026/07/23 15:21:58 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	AAnimal	*animals[10];

    //Test 0 - can we instantiate an element of type AAnimal?
    //animals[0] = new AAnimal();
    //nope -> passed
    
    std::cout << "TEST 1" << std::endl;
    std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
    for (int i = 0; i < 10; i++)  
        delete(animals[i]);
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "TEST 2" << std::endl;
    std::cout << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "TEST 3" << std::endl;
    std::cout << std::endl;
    Dog orig;
    Dog copy(orig);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "TEST 4" << std::endl;
    std::cout << std::endl;
    Cat a;
    Cat b;

    b = a;

    std::cout << std::endl;
    std::cout << "TEST 5" << std::endl;
    std::cout << std::endl;
    Dog* first = new Dog();
    std::string idea = "67";
    first->getBrain()->setIdea(idea, 67);
    Dog* second = new Dog(*first);
    delete first;
    std::cout << "THE IDEA IS " << second->getBrain()->getIdea(67) << std::endl;
    std::cout << "THE IDEA IS " << second->getBrain()->getIdea(555) << std::endl; 
    std::cout << second->getType() << std::endl;
    second->makeSound();
    delete second;
    
	return (0);
}
