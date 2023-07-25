#include "PhoneBook.hpp"

void Phonebook::SEARCH(){
	for (int i = 0; persons[i].flag == 1; i++){
		std::cout << i + 1 << "|";
		if(persons[i].getName().length() > 10)
			std::cout << std::setw(10) << persons[i].getName().substr(0,9) + "." << "|";
		else
			std::cout << std::setw(10) << persons[i].getName() << "|";
		if(persons[i].getSurname().length() > 10)
			std::cout << std::setw(10) << persons[i].getSurname().substr(0,9) + "." << "|";
		else
			std::cout << std::setw(10) << persons[i].getSurname() << "|";
		if(persons[i].getNickName().length() > 10)
			std::cout << std::setw(10) << persons[i].getNickName().substr(0,9) + "." << "|";
		else
			std::cout << std::setw(10) << persons[i].getNickName() << "|";
		std::cout << std::endl;
	}

	int select = 0;

	std::cout << "Choose a number between 1 and " << add << " : ";
	std::cin >> select;

	while(select > add || select < 1)
	{
		std::cout << std::endl << "Choose a number between 1 and " << add << " : ";
		std::cin >> select;
	}
	std::cout << "Name         :" << persons[select - 1].getName() << std::endl;
	std::cout << "Surname      :" << persons[select - 1].getSurname() << std::endl;
	std::cout << "Nickname     :" << persons[select - 1].getNickName() << std::endl;
	std::cout << "Phone Number :" << persons[select - 1].getPhoneNumber() << std::endl;
	std::cout << "D. Secret    :" << persons[select - 1].getDarkestSecret() << std::endl;
	std::cin.ignore();
}