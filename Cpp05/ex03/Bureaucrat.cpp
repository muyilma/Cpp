#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Anonim")
{ 
    grade = 0;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
    grade = other.grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooLowException();
    else if(grade > 150)
        throw GradeTooHighException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        grade = other.grade;

    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!\n";
}

const std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

std::ostream& operator<<(std::ostream &a,const Bureaucrat &b)
{
    a << b.getName() << " Bureaucrat grade:" << b.getGrade();
    return a;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {

        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}