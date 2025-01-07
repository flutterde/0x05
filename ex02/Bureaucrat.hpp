/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:36:48 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/06 10:36:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP 
#define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"

# ifndef IS_DEBUG_MODE
#define	IS_DEBUG_MODE 1
# endif

class	AForm;
class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string _name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();

		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		std::string	getName(void);
		int			getGrade(void) const;
		void		increment(void);
		void		decrement(void);
		void		signForm(AForm& fr);
		void		executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& brc);


#endif