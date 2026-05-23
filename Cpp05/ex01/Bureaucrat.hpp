#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

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
        void gradePlus();
        void gradeMinus();
        void singForm(Form &form);
};

std::ostream& operator<<(std::ostream &a,const Bureaucrat &b);

#endif