/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:18:36 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 13:24:15 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default_PresidentialPardon_name", 25, 5)
{
	if (IS_DEBUG_MODE)
		std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("Presidential_Pardon", 25, 5)
{
	if (IS_DEBUG_MODE)
		std::cout << "PresidentialPardonForm parametrized constructor called" << std::endl;
	this->target = _target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (IS_DEBUG_MODE)
		std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		AForm::operator=(obj);
		this->target = obj.target;
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget()
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNoTSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}