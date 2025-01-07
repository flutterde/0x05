/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:36:38 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/06 10:36:38 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default_name")
{
	if (IS_DEBUG_MODE)
		std::cout << "Bureaucrat befault constructor called." << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	if (IS_DEBUG_MODE)
		std::cout << "Bureaucrat parametrized constructor called." << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade)
{
	if (IS_DEBUG_MODE)
		std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "Bureaucrat copy assigment operator called." << std::endl;
	if (this != &obj)
		this->grade = obj.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	if (IS_DEBUG_MODE)
		std::cout << "Bureaucrat Destructor called." << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too Hight exception");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low exception");
}

std::string	Bureaucrat::getName(void)
{
	return (this->name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->grade);
}

void	Bureaucrat::increment(void)
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrement(void)
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

void		Bureaucrat::signForm(Form& fr)
{
	try
	{
		fr.beSigned(*this);
		std::cout << this->name << " signed " << fr.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't sign " << fr.getName() << "because" <<  e.what() << "." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& brc)
{
	os << brc.getName() << ", bureaucrat grade " << brc.getGrade();
	return (os);
}
