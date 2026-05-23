#include <string>
#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *ptrString = &string;
	std::string &refString = string;

	std::cout << "address of variable	:" << &string << std::endl;
	std::cout << "address of pointer	:" << ptrString << std::endl;
	std::cout << "address of reference	:" << &refString << std::endl;

	std::cout << "---------------------------------------" << std::endl;
	
	std::cout << "value of variable	:" << string << std::endl;
	std::cout << "value of pointer	:" << *ptrString << std::endl;
	std::cout << "value of ref		:" << refString << std::endl;
	return(0);
}