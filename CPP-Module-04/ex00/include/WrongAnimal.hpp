#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal&);
        WrongAnimal &operator=(const WrongAnimal&);

        void makeSound(void)const;

        std::string getType(void)const;
};