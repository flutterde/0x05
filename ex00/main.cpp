/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:36:28 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/06 10:36:28 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat newObj;
	Bureaucrat newObj3("0x0",  1);
	std::cout << newObj << std::endl;
	try
	{
		newObj.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << " ----------------------------- " << std::endl;
	try
	{
		newObj3.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << " ----------------------------- " << std::endl;
	try
	{
		Bureaucrat newObj2("0x0",  153);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
