#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
    private:
        Brain *_brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog&);
        Dog& operator=(const Dog&);

        void makeSound(void)const;

        void getIdeas(void)const;

        void setIdea(size_t , std::string);

};