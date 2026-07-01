#include "iter.hpp"
#include <iostream>

void topla(int sayi)
{
    std::cout << sayi << std::endl;
}   

int main()
{
    int array[] = {1, 2, 3, 4};

    
    ::iter(array, 4 ,topla);
}
