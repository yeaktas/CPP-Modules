#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_CPP

#include <string>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        std::string getName(void);
        int getGrade(void);

        void upGrade(void);
        void downGrade(void);

        // Exceptions
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what(void) const throw();
        }
	    class GradeTooLowException : public std::exception{
		    public:
			    virtual const char *what(void) const throw();
};
#endif