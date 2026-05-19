#include "Bureaucrat.hpp"

int main()
{
    try
    {
        const Bureaucrat a;
        const Bureaucrat b("mustafa",10);
        const Bureaucrat c(b);

        std::cout << a << std::endl << b << std::endl << c << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    
}