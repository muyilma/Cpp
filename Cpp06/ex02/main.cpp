#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void)
{
    int random;

    random = std::rand() % 3;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else 
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}


void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception& e) { } 

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception& e) { }

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception& e) { }
}

int main()
{
    std::srand(std::time(NULL));

    A *a = new A;
    identify(*a);

    for (int i = 1; i <= 3; i++)
    {
        std::cout << "\n[ TEST " << i << " ]" << std::endl;
        
        Base* rastgeleObje = generate();

        std::cout << "Pointer (Base*) : ";
        identify(rastgeleObje);

        std::cout << "Referans (Base&) : ";
        identify(*rastgeleObje);

        delete rastgeleObje;
    }
    delete a;
}