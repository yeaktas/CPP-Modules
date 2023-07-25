#include "FragTrap.hpp"

//constructors
FragTrap::FragTrap():ClapTrap(){

	std::cout << "Default FragTrap constructor called" << std::endl;

	this->_name = "FragTrap";
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_atackDamage = 30;
}
FragTrap::FragTrap(const FragTrap& copy){

	*this = copy;

}
FragTrap& FragTrap::operator=( const FragTrap& copy){

	
	this->_name = copy._name;
	this->_hitPoint = copy._hitPoint;
	this->_energyPoint = copy._energyPoint;
	this->_atackDamage = copy._atackDamage;

	return *this;
}
FragTrap::~FragTrap(){

	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void){

	std::cout << "high fives" << std::endl;
}