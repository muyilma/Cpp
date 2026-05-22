#include "AForm.hpp"

AForm::AForm() : name("Anonim"), sign(false), grade(150), execute_grade(150)
{
}

AForm::AForm(const AForm& other) : name(other.getName()), sign(other.getSign()), grade(other.getGrade()), execute_grade(other.getExecuteSignature())
{
}

AForm::AForm(const std::string name, bool sign, const int grade, const int execute_grade) : name(name), sign(sign), grade(grade), execute_grade(execute_grade)
{
    if (grade < 1)
        throw GradeTooLowException();
    else if(grade > 150)
        throw GradeTooHighException();
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
    return "No signature authorityr";
}


std::ostream& operator<<(std::ostream &os,const AForm &Aform)
{
    os << Aform.getName() << Aform.getSign() << Aform.getGrade() << Aform.getExecuteSignature(); 
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
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getExecuteSignature())
        throw AForm::GradeTooLowException();
        
    this->executeAction(); 
}