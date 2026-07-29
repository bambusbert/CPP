/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:06:29 by slambert          #+#    #+#             */
/*   Updated: 2026/07/29 15:21:14 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main ()
{
    IMateriaSource* src2 = new MateriaSource();
    IMateriaSource* src(src2);
    AMateria* tmp;
    
    tmp = new Ice();
    src->learnMateria(tmp);
    delete tmp;
    tmp = new Cure();
    src->learnMateria(tmp);
    delete tmp;
    src->learnMateria(NULL);
    
    ICharacter* me = new Character("me");
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("hihi");
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);

    delete bob;
    delete me;
    delete src;
    
    // return 0;
    std::cout << "--- 1. Testing MateriaSource & Overflow ---" << std::endl;
    src = new MateriaSource();
    tmp = new Ice();
    src->learnMateria(tmp);
    delete tmp;
    tmp = new Cure();
    src->learnMateria(tmp);
    delete tmp;
    tmp = new Ice();
    src->learnMateria(tmp);
    delete tmp;
    tmp = new Cure();
    src->learnMateria(tmp);
    delete tmp;
    // The 5th Materia should be rejected (nothing happens)
    AMateria* extraSpell = new Ice();
    src->learnMateria(extraSpell);
    delete extraSpell;

    std::cout << "\n--- 2. Testing Character Equip & Overflow ---" << std::endl;
    me = new Character("me");
    
    AMateria* tmp1 = src->createMateria("ice");
    me->equip(tmp1);
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    
    // The 5th equip should do nothing 
    AMateria* tmpReject = src->createMateria("ice");
    me->equip(tmpReject);
    delete tmpReject;

    std::cout << "\n--- 3. Testing Deep Copy of Character ---" << std::endl;
    Character* originalBob = new Character("bob");
    originalBob->equip(src->createMateria("cure"));
    Character* cloneBob = new Character(*originalBob); // Testing Copy Constructor
    delete originalBob; 
    
    // cloneBob should still be able to use the cloned 'cure' spell
    ICharacter* target = new Character("TargetDummy");
    cloneBob->use(0, *target);

    std::cout << "\n--- 4. Cleanup ---" << std::endl;
    delete me;
    delete cloneBob;
    delete target;
    delete src;
    
    return 0;
}
