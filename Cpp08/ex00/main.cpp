#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;
    std::list<int> list;

    for (int i = 10; i <= 100; i+=10)
    {
        numbers.push_back(i);
        list.push_back(i);
    }

    std::cout << "numbers: ";
    for (int i = 0; i < 10; i++)
        std::cout << numbers[i] << " ";
    
    std::list<int>::iterator it = list.begin();
    std::cout << std::endl << "list: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << *it << " ";
        *it++;
    }
    std::cout << std::endl ;
    int value = 50;
    try
    {
        std::cout << "Searching numbers array " << value << std::endl;
        std::vector<int>::iterator it = ::easyfind(numbers,value);
        std::cout << "Find Number: " << *it << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Searching list array " << value << std::endl;
        std::list<int>::iterator it = ::easyfind(list,value);
        std::cout << "Find Number: " << *it << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    
}
