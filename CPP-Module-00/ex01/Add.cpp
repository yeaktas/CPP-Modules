#include "PhoneBook.hpp"

void Phonebook::ADD(){

	persons[i].flag = 0;
	std::string temp;
	std::cout << "Name: ";
	getline(std::cin, temp);
	while(temp.empty())
	{
		std::cout << "Input cannot be empty." << std::endl << "Name: ";
		getline(std::cin, temp);
	}
	persons[i].setName(temp);
	
	std::cout << "Surname: ";
	getline(std::cin, temp);
	while(temp.empty())
	{
		std::cout << "Input cannot be empty." << std::endl << "Surname: ";
		getline(std::cin, temp);
	}
	persons[i].setSurname(temp);

	std::cout << "Nickname: ";
	getline(std::cin, temp);
	while(temp.empty())
	{
		std::cout << "Input cannot be empty." << std::endl << "Nickname: ";
		getline(std::cin, temp);
	}
	persons[i].setNickname(temp);

	std::cout << "Phonenumber: ";
	getline(std::cin, temp);
	while(temp.empty())
	{
		std::cout << "Input cannot be empty." << std::endl << "Phonenumber: ";
		getline(std::cin, temp);
	}
	persons[i].setPhoneNumber(temp);

	std::cout << "Darkest Secret: ";
	getline(std::cin, temp);
	while(temp.empty())
	{
		std::cout << "Input cannot be empty." << std::endl << "Darkest Secret: ";
		getline(std::cin, temp);
	}
	persons[i].setDarkestSecret(temp);
	persons[i].flag = 1;
	i++;
	i %= 8;
	if(add < 8)
		add++;
}