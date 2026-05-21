#include "Form.hpp"

Form::Form() : name("Anonim"), sign(false), grade(150), execute_grade(150)
{
}

Form::Form(const Form& other) : name(other.getName()), sign(other.getSign()), grade(other.getGrade()), execute_grade(other.getExecuteSignature())
{
}

Form::Form(const std::string name, bool sign, const int grade, const int execute_grade) : name(name), sign(sign), grade(grade), execute_grade(execute_grade)
{
    if (grade < 1)
        throw GradeTooLowException();
    else if(grade > 150)
        throw GradeTooHighException();
}

Form::~Form()
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->sign = other.sign;
    std::cout << "Form Copy assignment operator called" << std::endl;
    return *this;
}

std::string Form::getName() const {   
    return name;
}

bool Form::getSign() const {
    return sign;
}

int Form::getGrade() const {
    return grade;
}

int Form::getExecuteSignature() const {
    return execute_grade;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream &os,const Form &form)
{
    os << form.getName() << form.getSign() << form.getGrade() << form.getExecuteSignature(); 
    return os;
}

void Form::beSigned(const Bureaucrat &bro)
{
    if (bro.getGrade() <= this->getGrade())
        this->sign = true;
    else
        throw GradeTooLowException();
}