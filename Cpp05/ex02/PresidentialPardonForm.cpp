#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",false,25,5), target("Anonim")
{   
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{   
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm("PresidentialPardonForm",false,25,5), target(name)
{   
}

void PresidentialPardonForm::executeAction() const{
    std::cout << this->target << " Zaphod was pardoned by Beeblebrox." << std::endl;
}