/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:52:05 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/08 14:45:01 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		typedef	AForm* (Intern::*FormCreator)(std::string& target);
		AForm*	shrubberyCreator(std::string& target);
		AForm*	robotomyCreator(std::string& target);
		AForm*	presidentialCreator(std::string& target);

	public:
		Intern(void);
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);
		~Intern();
		AForm*	makeForm(std::string _form, std::string _target);
};

#endif
