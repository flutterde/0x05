/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:07:52 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 10:45:28 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

# ifndef IS_DEBUG_MODE
#define	IS_DEBUG_MODE 1
# endif

class	Bureaucrat;
class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		int const			gradeToSign;
		int const			gradeToExecute;
	public:
		AForm(void); // Default constructor
		AForm(const AForm& obj); // Copy constructor
		AForm&	operator=(const AForm& obj);
		AForm(std::string _name, int _gradeToSign, int _gradeToExecute);
		~AForm(); // Destructor

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

		virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& frm);

#endif
