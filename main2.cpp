#include <iostream>

int a(int value)
{    
    if (value == 10)
        throw 10;
    return value;
}

int b(int value)
{    
    return a(value);
}

int c(int value)
{    
    return b(value);
}

int main()
{
    try
    {
       c(10);
       std::cout << "Program Başarılı" << std::endl;
    }
    catch(int a)
    {
        std::cout << "Program Başarısız" << std::endl;
    }
    
    
}
