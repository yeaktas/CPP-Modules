#include "PhoneBook.hpp"

int main()
{
	Phonebook p;

	p.add = 0;
	p.i = 0;
	std::string tmp;

	while (69)
	{
		std::cout << "PHONEBOOK" << std::endl;
		getline(std::cin, tmp);
		if(!tmp.compare("ADD"))
			p.ADD();
		else if (!tmp.compare("SEARCH"))
			p.SEARCH();
		else if (!tmp.compare("EXIT"))
			exit(0);
	}
}
