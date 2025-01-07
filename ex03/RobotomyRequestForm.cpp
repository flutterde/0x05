/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:18:40 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 13:19:43 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default_Robotomy_name", 72, 45)
{
	if (IS_DEBUG_MODE)
		std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("Robotomy", 72, 45)
{
	if (IS_DEBUG_MODE)
		std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl;
	this->target = _target;
}


RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (IS_DEBUG_MODE)
		std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		AForm::operator=(obj);
		this->target = obj.target;
	}
	return (*this);
}


std::string	RobotomyRequestForm::getTarget()
{
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNoTSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::srand(std::time(0));
	int randomNum = std::rand() % 101;

	if (randomNum % 2)
		std::cout << this->target << " has been robotomized successfull" << std::endl;
	else
		std::cout << "robotomy failed." << std::endl;
}