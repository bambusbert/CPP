/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:22:52 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 15:33:39 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const unsigned int _gradeSign;
        const unsigned int _gradeExecute;
        void myExceptionThrower(unsigned int grade);
    public:
        AForm();
        AForm(const std::string& name, unsigned int gradeSign, unsigned int gradeExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        const std::string getName() const;
        bool getSigned() const;
        unsigned int getGradeSign() const;
        unsigned int getGradeExecute() const;
        void beSigned(Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
        virtual void beExecuted() const = 0;
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
        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &o, AForm *f);
std::ostream& operator<<(std::ostream &o, AForm &f);

#endif
