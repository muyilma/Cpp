#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "--- RASTGELE SINIF URETIMI TESTI ---" << std::endl;

    for (int i = 1; i <= 5; i++)
    {
        std::cout << "\n[ TEST " << i << " ]" << std::endl;
        
        Base* rastgeleObje = generate();

        std::cout << "Pointer (Base*) ile tespit  : ";
        identify(rastgeleObje);

        std::cout << "Referans (Base&) ile tespit : ";
        identify(*rastgeleObje);

        delete rastgeleObje;
    }
}