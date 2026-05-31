#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Anonim")
{ 
    grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
    grade = other.grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
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
	return "Grade too high!"; 
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::gradeMinus()
{
    if (grade  >= 150)
        throw GradeTooLowException();
    grade++;
    
}

void Bureaucrat::gradePlus()
{
    if (grade  <= 1)
        throw GradeTooHighException();
    grade--;
}


std::ostream& operator<<(std::ostream &a,const Bureaucrat &b)
{
    a << b.getName() << ", bureaucrat grade " << b.getGrade();
    return a;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout  << this->name << " signed " << form.getName() << std::endl;
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