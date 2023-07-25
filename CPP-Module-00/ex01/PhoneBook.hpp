#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>

class Contact{
private:
	std::string _name;
	std::string _surname;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
public:
	//setter
	void setName(std::string name);
	void setSurname(std::string surname);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phonenumber);
	void setDarkestSecret(std::string darkestsecret);
	//getter
	std::string getName(void);
	std::string getSurname(void);
	std::string getNickName(void);
	std::string getPhoneNumber(void);
	std::string getDarkestSecret(void);

	int flag;
};

class Phonebook{
	public:
	
	Contact persons[8];
	int i;
	int add;

	void ADD();
	void SEARCH();
};

#endif