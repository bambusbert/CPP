/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:23:09 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 16:21:03 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("anon Form"), _signed(false), _gradeSign(75), _gradeExecute(75)
{
}

Form::Form(const std::string &name, unsigned int gradeSign, unsigned int gradeExecute):
    _name(name), _signed(false), _gradeSign (gradeSign), _gradeExecute(gradeExecute)
{
    myExceptionThrower(gradeSign);
    myExceptionThrower(gradeExecute);
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed),
                                _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
    myExceptionThrower(other._gradeSign);
    myExceptionThrower(other._gradeExecute);
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

Form::~Form()
{
}

const std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

unsigned int Form::getGradeSign() const
{
    return _gradeSign;
}

unsigned int Form::getGradeExecute() const
{
    return _gradeExecute;
}

void Form::beSigned(Bureaucrat &b)
{
    if (!(b.getGrade() <= this->_gradeSign))
        throw GradeTooLowException();

    this->_signed = true;

}

void Form::myExceptionThrower(unsigned int grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

std::ostream& operator<<(std::ostream &o, Form *f)
{
    o << "Form name: " << f->getName() << ", " << "Signed: " << f->getSigned() << std::endl;
    o << "Grade Sign: " << f->getGradeSign() << ", " << "Grade Execute: " << f->getGradeExecute() << std::endl;
    return o;
}

std::ostream& operator<<(std::ostream &o, Form &f)
{
    o << "Form name: " << f.getName() << ", " << "Signed: " << f.getSigned() << std::endl;
    o << "Grade Sign: " << f.getGradeSign() << ", " << "Grade Execute: " << f.getGradeExecute() << std::endl;
    return o;
}
