#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe a;

    try
    {
         a.parser(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
}
