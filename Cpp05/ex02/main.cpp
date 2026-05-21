#include "Bureaucrat.hpp"

int main()
{
    try
    {
        const Bureaucrat a;
        const Bureaucrat b("mustafa",55);
        const Bureaucrat c(b);
         Form f1;
         Form f2("mustafa ea",false,50,50);
         Form f3(f2);

        std::cout << a << std::endl << b << std::endl << c << std::endl;
        std::cout << f1 << std::endl << f2 << std::endl << f3 << std::endl;
        f2.beSigned(b);
        f1.beSigned(a);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    
}