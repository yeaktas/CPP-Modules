#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrongmeta->getType() << " " << std::endl;
    std::cout << wrongcat->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    wrongmeta->makeSound();
    wrongcat->makeSound();

    delete i;
    delete j;
    delete meta;
    delete wrongmeta;
    delete wrongcat;
    return 0;
}