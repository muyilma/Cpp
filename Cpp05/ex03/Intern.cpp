#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{ 
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm* Intern::createShrubbery(const std::string& target){
    return new  ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target){
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target){
    return new  PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string formName [] = {"PresidentialPardonForm","RobotomyRequestForm","ShrubberyCreationForm"};

    AForm* (Intern::*funcAddress[])(const std::string&) = {&Intern::createPresidential, &Intern::createRobotomy, &Intern::createShrubbery};

    for(int i = 0; i < 3; i++)
    {
        if (formName[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*funcAddress[i])(target);
        }
    }
    return NULL;
}