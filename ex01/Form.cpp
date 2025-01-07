/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:07:57 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 09:11:40 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("default_name"), gradeToSign(50), gradeToExecute(50)
{
	if (IS_DEBUG_MODE)
		std::cout << "Form Default constructor called" << std::endl;
	this->isSigned = false;
}

Form::~Form(void)
{
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form& obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	if (IS_DEBUG_MODE)
		std::cout << "Form Copy constructor called" << std::endl;
	this->isSigned = obj.isSigned;
}

Form::Form(std::string _name, int _gradeToSign, int _gradeToExecute) : name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	if (IS_DEBUG_MODE)
		std::cout << "Form parametrized constructor called." << std::endl;
	this->isSigned = false;
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& obj)
{
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->isSigned = obj.isSigned;
	}
	return (*this);
}

void		Form::beSigned(Bureaucrat& br)
{
	if (this->isSigned)
		throw Form::AlreadySignedException();
	if (br.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::string	Form::getName() const
{
	return (this->name);
}

bool		Form::getIsSigned() const
{
	return (this->isSigned);
}

int			Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int			Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High Exception");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low Exception");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("Already Signed Exception");
}

std::ostream&	operator<<(std::ostream& os, const Form& frm)
{
	os << "name: " << frm.getName() << " is_Signed: " << (frm.getIsSigned() ? "True" : "False") << \
		" grade to sign " << frm.getGradeToSign() << " grade to execute " << frm.getGradeToExecute() << std::endl;
	return (os);
}
