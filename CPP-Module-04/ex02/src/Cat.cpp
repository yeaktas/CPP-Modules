#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "Cat Default Constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
    if(this->_brain == NULL)
    {
        perror("Cat Brain allacation failed");
        std::cerr << "Exiting the process now." << std::endl;
        exit(1);
    }
}

Cat::Cat(const Cat& copy): Animal()
{
    *this = copy;
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat()
{
    delete(this->_brain);
    std::cout << "Cat Deconstructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "Cat Assignation operator called" << std::endl;
    if(this == &src)
        return(*this);
    this->_type = src._type;
    this->_brain = new Brain();
    if(this->_brain == NULL)
    {
        perror("Cat Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
    }
    *this->_brain = *src._brain;
    return(*this);
}

void Cat::makeSound(void)const
{
    std::cout << this->getType() << " says: Meooww" << std::endl;
}

void Cat::getIdeas(void)const{
    for(int i = 0; i < 100; i++)
        std::cout << "\tIdea " << i << " of the Cat is: \"" << this->_brain->getIdeas(i) << "\"" << std::endl;
}

void Cat::setIdea(size_t i, std::string idea)
{
    this->_brain->setIdea(i, idea);
}