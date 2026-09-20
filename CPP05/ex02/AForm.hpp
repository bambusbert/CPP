/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:22:52 by slambert          #+#    #+#             */
/*   Updated: 2026/09/20 13:04:15 by slambert         ###   ########.fr       */
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
        const int _gradeSign;
        const int _gradeExecute;
        void myExceptionThrower(int grade);
        virtual void beExecuted() const = 0;
    public:
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        const std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;
        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
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

std::ostream& operator<<(std::ostream &o, const AForm *f);
std::ostream& operator<<(std::ostream &o, const AForm &f);

#endif
