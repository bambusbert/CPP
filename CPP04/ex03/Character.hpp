/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:59:14 by slambert          #+#    #+#             */
/*   Updated: 2026/08/17 17:33:56 by slambert         ###   ########.fr       */
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
        virtual ~Character();
        virtual std::string const &getName() const;
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
};

#endif
