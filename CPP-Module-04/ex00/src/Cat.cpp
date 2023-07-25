#include "Cat.hpp"

Cat::Cat(): Animal()
{
    this->_type = "Cat";
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& copy): Animal()
{
    *this = copy;
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Deconstructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "Cat Assignation operator called" << std::endl;
    if(this == &src)
        return(*this);
    this->_type = src._type;
    return(*this);
}

void Cat::makeSound(void)const
{
    std::cout << this->getType() << " says: Meooww" << std::endl;
}