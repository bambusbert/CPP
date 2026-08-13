/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:55 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 14:05:48 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

#define ASCII_TREE \
    "               ,@@@@@@@,\n" \
    "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n" \
    "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/88o\n" \
    "   ,%&\\%&&%&&%,@@@\\@@@/@@@[]88888|88888'\n" \
    "   %&&%&%&/%&%@@@@/ /@@@   `88\\88888'/88'\n" \
    "   %&%-&%-&%&&%@@ \\ \\/ /@  [] `888` /88'\n" \
    "   `%&\\%$#%&%'  [] \\ /     ||  []  |_\n" \
    "       `\"\"`     ||  |      ||  ||  ||\n" \
    "                ||  |      ||  ||  ||\n" \
    "             ___||__|______||__||__||___\n"

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        virtual void beExecuted() const;
};
