#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << "Dog default Constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
    if(this->_brain == NULL)
    {
        perror("Dog Brain allocation failed");
        std::cerr << "Exiting the process now." << std::endl;
        exit(1);
    }
}

Dog::Dog(const Dog& copy): Animal()
{
    *this = copy;
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog::~Dog()
{
    delete(this->_brain);
    std::cout << "Dog Deconstructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog Assignation operator called" << std::endl;
    if(this == &src)
        return(*this);
    this->_type = src._type;
    this->_brain = new Brain();
    if(this->_brain == NULL)
    {
        perror("Dog Brain allacation failed");
        std::cerr << "Exiting the process now." << std::endl;
        exit(1);
    }
    *this->_brain = *src._brain;
    return(*this);
}

void Dog::makeSound(void)const
{
    std::cout << this->getType() << " says: HawHav" << std::endl;
}

void Dog::getIdeas(void)const {
    for(int i = 0; i < 100; i++)
        std::cout << "\tIdea " << i << " od the Dog is: \"" << this->_brain->getIdeas(i) << "\"" << std::endl;
}

void Dog::setIdea(size_t i, std::string idea)
{
    this->_brain->setIdea(i, idea);
}