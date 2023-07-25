#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapons):_name(name), _Weapon(Weapons){

    std::cout  << "Constructor: " + this->_name << std::endl;

}

void HumanA::attack( void ){

    std::cout << this->_name + " attacks with their " << this->_Weapon.getType() << std::endl;

}

HumanA::~HumanA(){

    std::cout << "Destructor called" << std::endl;
}