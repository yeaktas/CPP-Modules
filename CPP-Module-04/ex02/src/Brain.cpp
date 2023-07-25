#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain& copy){
    *this = copy;
    std::cout << "Brain Copy Constructor called" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain Deconstructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& src){
    std::cout << "Brain Assignation operator called" << std::endl;
    if(this == &src)
        return(*this);
    for (int i = 0; i < 100; i++)
    {
        if(src._ideas[i].length() > 0)
            this->_ideas[i].assign(src._ideas[i]);
    }
    return(*this);
}

const std::string Brain::getIdeas(size_t i)const{
    if(i < 100)
        return(this->_ideas[i]);
    else
        return("Brain Shutdown because, there is only 100 ideas per brain.");
}

void    Brain::setIdea(size_t i, std::string idea)
{
    if(i < 100)
        this->_ideas[i] = idea;
    else
        std::cout << "Brain Shutdown because, there is only 100 ideas per brain." << std::endl;
}
