/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:07:52 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/06 18:55:39 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

# ifndef IS_DEBUG_MODE
#define	IS_DEBUG_MODE 1
# endif

class	Bureaucrat;
class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		int const			gradeToSign;
		int const			gradeToExecute;
	public:
		Form(void); // Default constructor
		Form(const Form& obj); // Copy constructor
		Form&	operator=(const Form& obj);
		Form(std::string _name, int _gradeToSign, int _gradeToExecute);
		~Form(); // Destructor

		class	GradeTooHighException : public std::exception {
			public:
				char const	*what() const	throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				char const	*what() const	throw();	
		};
		class	AlreadySignedException : public std::exception {
			public:
				char const	*what() const	throw();
		};

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat& br);
};

std::ostream&	operator<<(std::ostream& os, const Form& frm);

#endif
