/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:42:13 by slambert          #+#    #+#             */
/*   Updated: 2026/06/05 11:33:09 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main(void)
{
    Harl harli;

    harli.complain("DEBUG");
    harli.complain("INFO");
    harli.complain("WARNING");
    harli.complain("ERROR");
    harli.complain("asdf");
}