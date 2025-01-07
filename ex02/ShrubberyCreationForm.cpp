/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:18:45 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 13:21:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default_Shrubbery_name", 145, 137)
{
	if (IS_DEBUG_MODE)
		std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	this->target = "Shrubbery_default";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (IS_DEBUG_MODE)
		std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		AForm::operator=(obj);
		this->target = obj.target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("Shrubbery", 145, 137)
{
	if (IS_DEBUG_MODE)
		std::cout << "ShrubberyCreationForm parametrized constructor called" << std::endl;	
	this->target = _target;
}

char const	*ShrubberyCreationForm::FileOpennignException::what() const throw()
{
	return ("Can't open the file exception");
}

std::string	ShrubberyCreationForm::getTarget()
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNoTSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::string	fName = (this->target + "_shrubbery");
	std::ofstream	outFile(fName.c_str());
	if (!outFile)
		throw ShrubberyCreationForm::FileOpennignException();
	outFile << ASCII_TREE;
	outFile.close();
	if (IS_DEBUG_MODE)
		std::cout << "Shrubbery Created" << std::endl;
}
