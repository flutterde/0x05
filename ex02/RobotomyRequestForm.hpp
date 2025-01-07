/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:18:18 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 10:46:30 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm(void); // Default constructor
		RobotomyRequestForm(const RobotomyRequestForm& obj); // Copy constructor
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj); // Copy assignment operator
		~RobotomyRequestForm(); // Destructor
		void execute(Bureaucrat const& executor) const;
};

#endif
