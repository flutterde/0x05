/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:18:02 by ochouati          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:33 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

#define ASCII_TREE \
"              v .   ._, |_  .,\n" \
"           `-._\\/  .  \\ /    |/_\n" \
"               \\\\  _\\\\, y | \\\\\\\n" \
"         _\\_.___\\\\, \\/ -\\.||\n" \
"           `7-,--.`._||  / / ,\n" \
"           /'     `-. `./ / |/_.'\n" \
"                     |    |//\n" \
"                     |_    /\n" \
"                     |-   |\n" \
"                     |   =|\n" \
"                     |    |\n" \
"--------------------/ ,  . \\--------._\n"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();

		class	FileOpennignException : public std::exception {
			public:
				char const	*what() const	throw();
		};

		void execute(Bureaucrat const& executor) const;
		std::string	getTarget();
};

#endif
