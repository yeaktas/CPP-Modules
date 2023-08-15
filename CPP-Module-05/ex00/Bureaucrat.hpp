#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_CPP

#include <string>

class Bureaucrat {

    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        void GradeTooHighException(int grade);
        void GradeTooLowException(int grade);

        std::string getName(void);
        int getGrade(void);

        void upGrade(void);
        void downGrade(void);
};

#endif