#include "ScavTrap.hpp"

//constructors
ScavTrap::ScavTrap():ClapTrap(){

	std::cout << "Default ScavTrap constructor called" << std::endl;

	this->_name = "Default";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_atackDamage = 20;
	this->_isGuard = false;
}
ScavTrap::ScavTrap(const ScavTrap& copy){

	*this = copy;

}
ScavTrap& ScavTrap::operator=( const ScavTrap& copy){

	
	this->_name = copy._name;
	this->_hitPoint = copy._hitPoint;
	this->_energyPoint = copy._energyPoint;
	this->_atackDamage = copy._atackDamage;
	this->_isGuard = copy._isGuard;

	return *this;
}
ScavTrap::~ScavTrap(){

	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(){

	if(this->_isGuard == true)
	{
		std::cout << "ScavTrap is now out Gate keeper mode" << std::endl;
		this->_isGuard = false;
	}
	else
	{
		std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
		this->_isGuard = true;
	}
}