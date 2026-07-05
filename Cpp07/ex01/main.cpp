#include "iter.hpp"

void print(int number)
{
    std::cout << number << std::endl;
}   

int main()
{
    int array[] = {1, 2, 3, 4};
    
    ::iter(array, 4 ,print);
}
