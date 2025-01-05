

#ifndef BUREAUCRAT_HPP 
#define BUREAUCRAT_HPP
# include <iostream>

#define	IS_DEBUG_MODE 1

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
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
		int			getGrade(void);
		void		increment(void);
		void		decrement(void);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& brc);


#endif