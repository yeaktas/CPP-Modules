#pragma once

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal&);
        Animal& operator=(const Animal&);

        virtual void makeSound(void)const = 0;

        std::string getType(void)const;
};