/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:59:14 by slambert          #+#    #+#             */
/*   Updated: 2026/07/28 14:37:51 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string const _name;
        AMateria* _inventory[4];
        void empty_inv();
        void free_inv();
        void clone_inv(const Character &other);
    public:
        Character();
        Character(const std::string name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif
