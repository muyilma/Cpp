#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(time(NULL));
    
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            Bureaucrat boss("Boss", 1);
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
        }
        rrf = someRandomIntern.makeForm("non-form", "Bender");
        
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}