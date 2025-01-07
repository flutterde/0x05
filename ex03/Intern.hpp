/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:52:05 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 19:52:06 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>

class Intern
{
	private:

	public:
		Intern(void); // Default constructor
		Intern(const Intern& obj); // Copy constructor
		Intern&	operator=(const Intern& obj); // Copy assignment operator
		~Intern(); // Destructor

};

#endif
