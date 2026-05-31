#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat anonim;
        Bureaucrat mustafa("Mustafa",112);
        
        std::cout << anonim << std::endl;
        std::cout << mustafa << std::endl;
        
        for (int i = 0; i < 50; i++)
            mustafa.gradePlus();
        std::cout << mustafa << std::endl;
        
        anonim.gradeMinus();
        std::cout << anonim << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    try
    {
        Bureaucrat mustafa("Mustafa",112);
        Bureaucrat CopyCo(mustafa);
        Bureaucrat boss("boss",1);

        std::cout << CopyCo << std::endl;
        CopyCo = boss;
        std::cout << CopyCo << std::endl;
        Bureaucrat wrong("wrong", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}