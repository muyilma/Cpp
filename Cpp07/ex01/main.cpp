#include "iter.hpp"

template <typename T>
void print(T &number)
{
    std::cout << number << std::endl;
}   

int main()
{
    int arrayInt[] = {1, 2, 3, 4};
    std::string arrayStr[] = {"mustafa","emre","yılmaz"};
    
    ::iter(arrayInt, 4 ,print<int>);
    ::iter(arrayStr, 3 ,print<std::string>);
}
