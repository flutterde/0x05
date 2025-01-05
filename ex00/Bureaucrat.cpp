

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("Default_name")
{
	if (IS_DEBUG_MODE)
		std::cout << "Bureaucrat befault constructor called." << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (IS_DEBUG_MODE)
		std::cout << "Bureaucrat copy assigment operator called." << std::endl;
	*this = obj;
	return (*this);
}


Bureaucrat::~Bureaucrat()
{
	if (IS_DEBUG_MODE)
		std::cout << "Bureaucrat Destructor called." << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too Hight exception");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low exception");
}

std::string	Bureaucrat::getName(void)
{
	return (this->name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->grade);
}

void	Bureaucrat::increment(void)
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrement(void)
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& brc)
{
	os << brc.getName() << ", bureaucrat grade " << brc.getGrade();
	return (os);
}