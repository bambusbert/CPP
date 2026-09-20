/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:22:52 by slambert          #+#    #+#             */
/*   Updated: 2026/09/20 12:27:06 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const unsigned int _gradeSign;
        const unsigned int _gradeExecute;
        void myExceptionThrower(unsigned int grade);
    public:
        Form();
        Form(const std::string& name, unsigned int gradeSign, unsigned int gradeExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        const std::string getName() const;
        bool getSigned() const;
        unsigned int getGradeSign() const;
        unsigned int getGradeExecute() const;
        void beSigned(Bureaucrat& b);
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &o, const Form *f);
std::ostream& operator<<(std::ostream &o, const Form &f);

#endif
