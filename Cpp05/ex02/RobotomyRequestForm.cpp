#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",false,72,45), target("Anonim")
{ 
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm("RobotomyRequestForm",false,72,45), target(name)
{
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* DRRRRRR! ZZZZZZZZZ! BAM BAM BAM! * (Korkutucu matkap sesleri...)" << std::endl;

    std::srand(time(NULL));

    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->target << ". It's still a human." << std::endl;

}
