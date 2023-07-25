#include "Dog.hpp"

Dog::Dog(): Animal()
{
    this->_type = "Dog";
    std::cout << "Dog default Constructor called" << std::endl;
}

Dog::Dog(const Dog& copy): Animal()
{
    *this = copy;
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Deconstructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog Assignation operator called" << std::endl;
    if(this == &src)
        return(*this);
    this->_type = src._type;
    return(*this);
}

void Dog::makeSound(void)const
{
    std::cout << this->getType() << " says: HawHav" << std::endl;
}