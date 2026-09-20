/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:44:55 by slambert          #+#    #+#             */
/*   Updated: 2026/09/20 13:05:21 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("anon"), _grade(75)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    myExceptionThrower(grade);
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
    myExceptionThrower(other._grade);
    _grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        // name stays the same, because it has to be const
        myExceptionThrower(other._grade);
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(Form& f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << this->_name << " couldn't sign " << f.getName() << " because ";
        std::cout << this->_name << " is not a good enough bureaucrat" << std::endl;
    }
}

void Bureaucrat::myExceptionThrower(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat *b)
{
    o << b->getName() << ", bureaucrat grade " << b->getGrade() << "." << std::endl;
    return o;
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return o;
}
