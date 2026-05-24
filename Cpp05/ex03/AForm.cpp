#include "AForm.hpp"

AForm::AForm() : name("Anonim"), sign(false), grade(150), execute_grade(150)
{
}

AForm::AForm(const AForm& other) : name(other.getName()), sign(other.getSign()), grade(other.getGrade()), execute_grade(other.getExecuteSignature())
{
}

AForm::AForm(const std::string name, bool sign, const int grade, const int execute_grade) : name(name), sign(sign), grade(grade), execute_grade(execute_grade)
{
    if (grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    else if(grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->sign = other.sign;
    return *this;
}

std::string AForm::getName() const {   
    return name;
}

bool AForm::getSign() const {
    return sign;
}

int AForm::getGrade() const {
    return grade;
}

int AForm::getExecuteSignature() const {
    return execute_grade;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char * AForm::NotSignedException::what() const throw()
{
    return "No signature authority";
}


std::ostream& operator<<(std::ostream &os,const AForm &Aform)
{
     os << "Name: " << Aform.getName() << " | Signed: " << (Aform.getSign() ? "Yes" : "No")
       << " | Grade: " << Aform.getGrade() << " | Execute Grade: " << Aform.getExecuteSignature();
    return os;
}

void AForm::beSigned(const Bureaucrat &bro)
{
    if (bro.getGrade() <= this->getGrade())
        this->sign = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSign())
        throw NotSignedException();
    if (executor.getGrade() > this->getExecuteSignature())
        throw GradeTooLowException();
        
    this->executeAction(); 
}