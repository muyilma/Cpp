#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();   
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(std::string name, int grade);
        Bureaucrat& operator=(const Bureaucrat& other);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        const std::string getName() const;
        int getGrade() const;
        void signForm(AForm &form);
        void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream &a,const Bureaucrat &b);

#endif