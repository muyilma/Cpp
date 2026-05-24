#include "Bureaucrat.hpp"

int main()
{
    try
    {
        const Bureaucrat anonim;
        const Bureaucrat mustafa("Mustafa",112);
        
        std::cout << anonim << std::endl;
        std::cout << mustafa << std::endl;
        
        const Bureaucrat boss("Boss",1000);
        std::cout << boss << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}