#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));


    for (int i = 1; i <= 5; i++)
    {
        std::cout << "\n[ TEST " << i << " ]" << std::endl;
        
        Base* rastgeleObje = generate();

        std::cout << "Pointer (Base*) : ";
        identify(rastgeleObje);

        std::cout << "Referans (Base&) : ";
        identify(*rastgeleObje);

        delete rastgeleObje;
    }
}