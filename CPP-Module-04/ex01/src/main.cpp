#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
// {    const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     const WrongAnimal* wrongmeta = new WrongAnimal();
//     const WrongAnimal* wrongcat = new WrongCat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     std::cout << wrongmeta->getType() << " " << std::endl;
//     std::cout << wrongcat->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     wrongmeta->makeSound();
//     wrongcat->makeSound();

//     delete i;
//     delete j;
//     delete meta;
//     delete wrongmeta;
//     delete wrongcat;
//     return 0;}
    // {
    //     const Animal* j = new Dog();
    //     const Animal* i = new Cat();
    //     delete j;//should not create a leak
    //     delete i;
    //     return 0;
    // }
    {
        const Animal *meta[10];
        for (int i = 0; i < 10; i++)
        {
            if(i % 2)
                meta[i] = new Cat();
            else
                meta[i] = new Dog();
        }
        std::cout << std::endl;

        for (int i = 0; i < 10; i++)
        {
            std::cout << std::endl;
            std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
            meta[i]->makeSound();
            std::cout << std::endl;
        }
        for(int i = 0; i < 10; i++)
            delete(meta[i]);
        std::cout << std::endl;

        Dog *a = new Dog();
        // Cat *a = new Cat();

        a->setIdea(0, "I have to sniff it");
        a->setIdea(1, "I have to pee on it");
        a->setIdea(101, "some shit");
        a->setIdea(77, "I love my master");

        Dog *b = new Dog(*a);
        //  Cat *b = new Cat(*a);

        std::cout << std::endl;

        std::cout << "The " << a->getType() << " a has the following ideas: \n";
        a->getIdeas();
        std::cout << std::endl;
        delete(a);

        std::cout << "The " << b->getType() << " b has the following ideas: \n";
        b->getIdeas();
        std::cout << std::endl;
        delete(b);
        // system("leaks Brain");
        return(0);
    }
}