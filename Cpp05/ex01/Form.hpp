#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool sign;
        const int grade;
        const int execute_grade;
    public:
        Form(const std::string name, bool sign, const int grade, const int execute_grade);
        Form();
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw();
        };
        void beSigned(const Bureaucrat &bro);
        std::string getName() const;
        bool getSign() const;
        int getGrade() const;
        int getExecuteSignature() const;

};

std::ostream& operator<<(std::ostream &a,const Form &b);

#endif