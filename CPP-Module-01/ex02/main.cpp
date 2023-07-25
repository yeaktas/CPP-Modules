#include <iostream>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << std::endl;
    std::cout << "string adress    : " << &brain << std::endl;
    std::cout << "stringptr adress : " << &stringPTR << std::endl;
    std::cout << "stringREF adress : " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "string value     : " << brain << std::endl;
    std::cout << "stringptr value  : " << *stringPTR << std::endl;
    std::cout << "stringREF value  : " << stringREF << std::endl;
} 