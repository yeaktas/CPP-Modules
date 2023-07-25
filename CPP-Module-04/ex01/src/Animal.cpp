#include "Animal.hpp"

Animal::Animal(): _type("Default")
{
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
    *this = copy;
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& src)
{
    std::cout << "Animal Assignation operator called" << std::endl;
    if(this == &src)
        return(*this);
    this->_type = src._type;
    return(*this);
}

void Animal::makeSound(void)const
{
    std::cout << "This animal doesnt make any sound." << std::endl;
}

std::string Animal::getType(void)const
{
    return(this->_type);
}