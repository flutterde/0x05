/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:52:09 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/08 10:34:36 by ochouati         ###   ########.fr       */
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

AForm *Intern::makeForm(std::string _form, std::string _target)
{
	int x = -1;
	AForm *newObj;
	std::string arr[3] = {"shrubbery request", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (_form == arr[i])
		{
			x = i;
			break;
		}
	}

	switch (x)
	{
	case 0:
		newObj = new ShrubberyCreationForm(_target);
		break;
	case 1:
		newObj = new RobotomyRequestForm(_target);
		break;
	case 2:
		newObj = new PresidentialPardonForm(_target);
		break;
	default:
		newObj = NULL;
		break;
	}
	newObj != NULL ? (std::cout << "Intern creates " << _form << std::endl) \
	: (std::cerr << "Error: Form name " << _form << " is not recognized!" << std::endl);
	return (newObj);
}
