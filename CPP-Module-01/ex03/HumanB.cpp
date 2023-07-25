#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name){

    std::cout  << "Constructor: " + this->_name << std::endl;

}

void HumanB::setWeapon(Weapon &Weapon){

    _Weapon = &Weapon;

}

void HumanB::attack( void ){

    std::cout << this->_name + " attacks with their " << this->_Weapon->getType() << std::endl;

}

HumanB::~HumanB(){

    std::cout << "Destructor called" << std::endl;
}

