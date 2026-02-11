#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{ 
    name = "Anonim";
    grade = 0;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    name = name.grade;
    grade = other.grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    try
    {
        if (grade < 0 || grade > 150)
            throw 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    this->name = name;
    this->grade = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        name = other.name  ;
        grade = other.grade;
    }
    return this*;
}

std::string Bureaucrat::GradeTooHighException()
{
	return "Grade too high!\n";
}

std::string Bureaucrat::GradeTooLowException()
{
	return "Grade too low!\n";
}