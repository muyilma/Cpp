#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void monitorUsers(const Bureaucrat mustafa, const Bureaucrat boss, const Bureaucrat anonymous)
{
    std::cout << "---Users---" << std::endl;
    std::cout << anonymous << std::endl;
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
        Bureaucrat anonymous;
        monitorUsers(mustafa,boss,anonymous);
        
        PresidentialPardonForm pardon("pardon");
        ShrubberyCreationForm shrubbery("Shrubbery");
        RobotomyRequestForm robotomy("Robotomy");
        mointorForms(pardon,shrubbery,robotomy);

        std::cout << "\n---Pardon Signed---" << std::endl;
        anonymous.signForm(pardon);
        mustafa.signForm(pardon);
        boss.signForm(pardon);

        std::cout << "\n---Pardon Execute---" << std::endl;
        anonymous.executeForm(pardon);
        mustafa.executeForm(pardon);
        boss.executeForm(pardon);

        std::cout << "\n---Shrubbery Signed---" << std::endl;
        anonymous.signForm(shrubbery);
        mustafa.signForm(shrubbery);
        boss.signForm(shrubbery);

        std::cout << "\n---Shrubbery Execute---" << std::endl;
        anonymous.executeForm(shrubbery);
        mustafa.executeForm(shrubbery);
        boss.executeForm(shrubbery);

        std::cout << "\n---Robotomy Execute---" << std::endl;
        anonymous.executeForm(robotomy);
        mustafa.executeForm(robotomy);
        boss.executeForm(robotomy);
        
        std::cout << "\n---Robotomy Signed---" << std::endl;
        anonymous.signForm(robotomy);
        mustafa.signForm(robotomy);
        boss.signForm(robotomy);

        std::cout << "\n---Robotomy Execute---" << std::endl;
        anonymous.executeForm(robotomy);
        mustafa.executeForm(robotomy);
        boss.executeForm(robotomy);        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}