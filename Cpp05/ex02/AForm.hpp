#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int grade;
        const int execute_grade;
    public:
        AForm(const std::string name, bool sign, const int grade, const int execute_grade);
        AForm();
        ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        class GradeTooHighException : public std::exception
        {
            const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
             const char * what() const throw();
        };
        void beSigned(const Bureaucrat &bro);
        std::string getName() const;
        bool getSign() const;
        int getGrade() const;
        int getExecuteSignature() const;

};

std::ostream& operator<<(std::ostream &a,const AForm &b);

#endif