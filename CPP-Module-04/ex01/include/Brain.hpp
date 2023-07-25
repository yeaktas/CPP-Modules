#pragma once

#include <string>
#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain&);
        Brain& operator=(const Brain&);

        const std::string getIdeas(size_t)const;

        void setIdea(size_t, std::string);
};