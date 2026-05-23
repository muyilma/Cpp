#include <iostream>

void a()
{    
    std::cout << "a çalıştı" << std::endl;
}

void b()
{    
    try
    {
       throw 10;
        std::cout << "b çalıştı" << std::endl;
    }
    catch(int a)
    {
        std::cout << "B Programı Başarısız" << std::endl;
    }   
}

void c()
{    
    std::cout << "c çalıştı" << std::endl;
}

int main()
{
    try
    {
        a();
        b();
        c();
        std::cout << "Program Başarılı" << std::endl;
    }
    catch(int a)
    {
        std::cout << "Program Başarısız" << std::endl;
    }
    
    
}
