#include "PhoneBook.hpp"

void Contact::setName(std::string name){
	_name = name;
}
std::string Contact::getName( void ){
	return _name;
}


void Contact::setSurname(std::string surname){
	_surname = surname;
}
std::string Contact::getSurname( void ){
	return _surname;
}


void Contact::setNickname(std::string nickname){
	_nickname = nickname;
}
std::string Contact::getNickName( void ){
	return _nickname;
}


void Contact::setPhoneNumber(std::string phonenumber){
	_phoneNumber = phonenumber;
}
std::string Contact::getPhoneNumber( void ){
	return _phoneNumber;
}


void Contact::setDarkestSecret(std::string darkestsecret){
	_darkestSecret = darkestsecret;
}
std::string Contact::getDarkestSecret( void ){
	return _darkestSecret;
}