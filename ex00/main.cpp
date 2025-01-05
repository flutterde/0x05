
#include "Bureaucrat.hpp"


int	main()
{
	Bureaucrat newObj;

	std::cout << newObj << std::endl;
	try
	{
		newObj.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
