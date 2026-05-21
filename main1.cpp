#include <iostream>

int a(int value)
{    
    if (value == 10)
        return -1;
    return value;
}

int b(int value)
{    
    if (a(value) == -1)
        return -1;
    return a(value);
}

int c(int value)
{    
    if (b(value) == -1)
        return -1;
    return b(value);
}

int main()
{
    if ( c(-1) == -1)
    {
        std::cout << "Program Başarısız" << std::endl;
        exit(1);
    }
    std::cout << "Program Başarılı" << std::endl;
}
