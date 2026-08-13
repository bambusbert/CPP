/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:23:09 by slambert          #+#    #+#             */
/*   Updated: 2026/08/12 16:21:03 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("anon AForm"), _signed(false), _gradeSign(75), _gradeExecute(75)
{
}

AForm::AForm(const std::string &name, unsigned int gradeSign, unsigned int gradeExecute) :
	_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	myExceptionThrower(gradeSign);
	myExceptionThrower(gradeExecute);
}

AForm::AForm(const AForm &other) :
	_name(other._name), _signed(other._signed), _gradeSign(other._gradeSign),
	_gradeExecute(other._gradeExecute)
{
	myExceptionThrower(other._gradeSign);
	myExceptionThrower(other._gradeExecute);
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

unsigned int AForm::getGradeSign() const
{
	return _gradeSign;
}

unsigned int AForm::getGradeExecute() const
{
	return _gradeExecute;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (!(b.getGrade() <= this->_gradeSign))
		throw GradeTooLowException();

	this->_signed = true;
}

void AForm::execute(Bureaucrat &b)
{
	if (!_signed)
		throw FormNotSignedException();
	if (!(b.getGrade() <= this->getGradeExecute()))
		throw GradeTooLowException();
	this->beExecuted();
}

void AForm::myExceptionThrower(unsigned int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

std::ostream &operator<<(std::ostream &o, AForm *f)
{
	o << "AForm name: " << f->getName() << ", " << "Signed: " << f->getSigned()
	  << ", Grade Sign: " << f->getGradeSign() << ", "
	  << "Grade Execute: " << f->getGradeExecute() << std::endl;
	return o;
}

std::ostream &operator<<(std::ostream &o, AForm &f)
{
	o << "AForm name: " << f.getName() << ", " << "Signed: " << f.getSigned()
	  << ", Grade Sign: " << f.getGradeSign() << ", "
	  << "Grade Execute: " << f.getGradeExecute() << std::endl;
	return o;
}
