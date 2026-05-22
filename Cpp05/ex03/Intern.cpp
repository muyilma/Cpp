#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{ 
}

Intern::Intern(const Intern& other)
{
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
    return *this;
}

AForm* Intern::createShrubbery(const std::string& target){
    return new  ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target){
    return new RobotomyRequestForm();
}

AForm* Intern::createPresidential(const std::string& target){
    return new  PresidentialPardonForm(target);
}

AForm* makeForm(const std::string& name, const std::string& target)
{
    std::string formName [] = {"PresidentialPardonForm","RobotomyRequestForm","ShrubberyCreationForm"};

    AForm *funcAdress [] = { &createPresidential,&createRobotomy,&createShrubbery };

    for(int i = 0; i < 3; i++)
    {
        if (formName[i] == name)
        {
            return funcAdress[i](target);
        }
    }
    return NULL;
}