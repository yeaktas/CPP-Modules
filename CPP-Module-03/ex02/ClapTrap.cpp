#include "ClapTrap.hpp"

//constructors
ClapTrap::ClapTrap(){

	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->_name = "ClapTrap";
	this->_hitPoint = 10;
	this->_energyPoint = 10;
	this->_atackDamage = 0;
}
ClapTrap::ClapTrap(const ClapTrap& copy){

	*this = copy;

}
ClapTrap& ClapTrap::operator=( const ClapTrap& copy){

	this->_name = copy._name;
	this->_hitPoint = copy._hitPoint;
	this->_energyPoint = copy._energyPoint;
	this->_atackDamage = copy._atackDamage;

	return *this;
}
ClapTrap::~ClapTrap(){

	std::cout << "ClapTrap destructor called" << std::endl;
}

std::string ClapTrap::getName(void) {

	return _name;
}

int ClapTrap::getAtack(void) {

	return _atackDamage;
}

void ClapTrap::attack( const std::string& target){

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_atackDamage << " point of damage!" << std::endl;
	this->_energyPoint--;
}
void ClapTrap::takeDamage( unsigned int amount) {

	std::cout << "Take damage: " << this->_name << std::endl;
	_hitPoint -= amount;

}
void ClapTrap::beRepaired(unsigned int amount) {

	std::cout << "Repaired: " << this->_name << std::endl;
	_hitPoint += amount;

}
