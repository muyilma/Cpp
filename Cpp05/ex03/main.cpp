#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(time(NULL));
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Bürokratlar Oluşturuluyor..." << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    try
    {
        Bureaucrat boss;       
        Bureaucrat stajyer("Stajyer", 150); 

        ShrubberyCreationForm shrubbery("Bahce");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << boss << std::endl;
        std::cout << stajyer << std::endl;

        std::cout << "\n=======================================================" << std::endl;
        std::cout << "[TEST 1] SHRUBBERY CREATION FORM (İstenen: Sign 145, Exec 137)" << std::endl;
        std::cout << "=======================================================" << std::endl;

        stajyer.signForm(shrubbery); 
        boss.signForm(shrubbery);    
        stajyer.executeForm(shrubbery); 
        boss.executeForm(shrubbery);   

        std::cout << "\n=======================================================" << std::endl;
        std::cout << "[TEST 2] ROBOTOMY REQUEST FORM (İstenen: Sign 72, Exec 45)" << std::endl;
        std::cout << "=======================================================" << std::endl;

        boss.signForm(robotomy);

        boss.executeForm(robotomy); 
        boss.executeForm(robotomy);
        boss.executeForm(robotomy);

        std::cout << "\n=======================================================" << std::endl;
        std::cout << "[TEST 3] PRESIDENTIAL PARDON FORM (İstenen: Sign 25, Exec 5)" << std::endl;
        std::cout << "=======================================================" << std::endl;

        boss.signForm(pardon);
        boss.executeForm(pardon); 

        std::cout << "\n=======================================================" << std::endl;
        std::cout << "[TEST 4] İMZASIZ FORM ÇALIŞTIRMA DENEMESİ" << std::endl;
        std::cout << "=======================================================" << std::endl;

        PresidentialPardonForm imzasizForm("Suclu");
        boss.executeForm(imzasizForm); 
    }
    catch (std::exception &e)
    {
        std::cerr << "Main içindeki kritik hata: " << e.what() << std::endl;
    }
}
