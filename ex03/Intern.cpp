/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:52:09 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 19:52:10 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern& obj)
{
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	std::cout << "Intern Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		// Add any assignment logic here
	}
	return (*this);
}
