#include "Zombie.hpp"

Zombie::Zombie(){
    std::cout << "constructor is called" << std::endl;
}

Zombie::Zombie(std::string _name){

    setName(_name);
}

void Zombie::setName(std::string _name){

    this->Name = _name;
}

std::string Zombie::getName( void ) {

    return this->Name;
}

void Zombie::announce( void ) {

    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;

}

Zombie::~Zombie() {
    std::cout << "destructor is called" << std::endl;
}
