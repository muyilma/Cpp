#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void monitorUsers(const Bureaucrat mustafa, const Bureaucrat boss, const Bureaucrat anonim)
{
    std::cout << "---Users---" << std::endl;
    std::cout << anonim << std::endl;
    std::cout << mustafa << std::endl;
    std::cout << boss << std::endl;
}

void mointorForms(PresidentialPardonForm pardon, ShrubberyCreationForm shrubbery, RobotomyRequestForm robotomy)
{
    std::cout << "\n---Forms---" << std::endl;
    std::cout << pardon << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
}

int main()
{
    std::srand(std::time(NULL));
    try
    {
        Bureaucrat mustafa("Mustafa",112);
        Bureaucrat boss("Boss",1);
        Bureaucrat anonim;
        monitorUsers(mustafa,boss,anonim);
        
        PresidentialPardonForm pardon("pardon");
        ShrubberyCreationForm shrubbery("Shrubbery");
        RobotomyRequestForm robotomy("Robotomy");
        mointorForms(pardon,shrubbery,robotomy);

        std::cout << "\n---Pardon Signed---" << std::endl;
        anonim.signForm(pardon);
        mustafa.signForm(pardon);
        boss.signForm(pardon);

        std::cout << "\n---Pardon Execute---" << std::endl;
        anonim.executeForm(pardon);
        mustafa.executeForm(pardon);
        boss.executeForm(pardon);

        std::cout << "\n---Shrubbery Signed---" << std::endl;
        anonim.signForm(shrubbery);
        mustafa.signForm(shrubbery);
        boss.signForm(shrubbery);

        std::cout << "\n---Shrubbery Execute---" << std::endl;
        anonim.executeForm(shrubbery);
        mustafa.executeForm(shrubbery);
        boss.executeForm(shrubbery);

        std::cout << "\n---Robotomy Execute---" << std::endl;
        anonim.executeForm(robotomy);
        mustafa.executeForm(robotomy);
        boss.executeForm(robotomy);
        
        std::cout << "\n---Robotomy Signed---" << std::endl;
        anonim.signForm(robotomy);
        mustafa.signForm(robotomy);
        boss.signForm(robotomy);

        std::cout << "\n---Robotomy Execute---" << std::endl;
        anonim.executeForm(robotomy);
        mustafa.executeForm(robotomy);
        boss.executeForm(robotomy);        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}