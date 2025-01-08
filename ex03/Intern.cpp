/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:52:09 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/08 14:06:03 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	if (IS_DEBUG_MODE)
		std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern(void)
{
	if (IS_DEBUG_MODE)
		std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "Intern Copy constructor called" << std::endl;
	*this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
	(void)obj;
	if (IS_DEBUG_MODE)
		std::cout << "Intern Copy assignment operator called" << std::endl;
	return (*this);
}

AForm*	Intern::shrubberyCreator(std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::robotomyCreator(std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::presidentialCreator(std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string _form, std::string _target)
{
	std::string arr[3] = {"shrubbery request", "robotomy request", "presidential pardon"};
	FormCreator creators[3] = {
		&Intern::shrubberyCreator,
		&Intern::robotomyCreator,
		&Intern::presidentialCreator,
	};
	for (int i = 0; i < 3; i++)
	{
		if (_form == arr[i])
		{
			std::cout << "Intern creates " << _form << std::endl;
			return ((this->*creators[i])(_target));
		}
	}
	std::cerr << "Error: Form name " << _form << " is not recognized!" << std::endl;
	return (NULL);
}
