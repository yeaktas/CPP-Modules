#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
    private:
        Brain* _brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat&);
        Cat& operator=(const Cat&);

        void makeSound(void)const;

        void getIdeas(void)const;

        void setIdea(size_t, std::string);
};