/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:07:57 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 17:11:39 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("default_name"), gradeToSign(50), gradeToExecute(50)
{
	if (IS_DEBUG_MODE)
		std::cout << "AForm Default constructor called" << std::endl;
	this->isSigned = false;
}

AForm::~AForm(void)
{
	if (IS_DEBUG_MODE)
		std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const AForm& obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	if (IS_DEBUG_MODE)
		std::cout << "AForm Copy constructor called" << std::endl;
	this->isSigned = obj.isSigned;
}

AForm::AForm(std::string _name, int _gradeToSign, int _gradeToExecute) : name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	if (IS_DEBUG_MODE)
		std::cout << "AForm parametrized constructor called." << std::endl;
	this->isSigned = false;
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "AForm Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->isSigned = obj.isSigned;
	}
	return (*this);
}

void		AForm::beSigned(Bureaucrat& br)
{
	if (this->isSigned)
		throw AForm::AlreadySignedException();
	if (br.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::string	AForm::getName() const
{
	return (this->name);
}

bool		AForm::getIsSigned() const
{
	return (this->isSigned);
}

int			AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int			AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High Exception");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low Exception");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("Already Signed Exception");
}

const char *AForm::FormNoTSignedException::what() const throw()
{
	return ("Form Not Signed Exception");
}

std::ostream&	operator<<(std::ostream& os, const AForm& frm)
{
	os << "name: " << frm.getName() << " is_Signed: " << (frm.getIsSigned() ? "True" : "False") << \
		" grade to sign " << frm.getGradeToSign() << " grade to execute " << frm.getGradeToExecute() << std::endl;
	return (os);
}
