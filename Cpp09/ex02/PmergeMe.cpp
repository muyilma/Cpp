#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{ 
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    (void)other;

}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}

int value_parser(char *argv)
{
    if (!argv || argv[0] == '\0')
        throw std::out_of_range("Error");


    for (int i = 0; argv[i] != '\0'; ++i)
    {
        if (!std::isdigit(argv[i]))
            throw std::out_of_range("Error");
    }
    
    long number = std::strtol(argv, NULL, 10);

    if (number < 0 || number > 2147483647)
        throw std::out_of_range("Error");

    return static_cast<int>(number);
}

void PmergeMe::parser(int argc,char **argv)
{
    bool single = false;
    if (argc <= 1)
        throw std::out_of_range("Error");
    argc--;
    if (!(argc % 2 == 0))
    {
        single = true;
        argc--;
    }
    argv++;
    while (argc)
    {
        int value = value_parser(*argv++);
        int value2 = value_parser(*argv++);
        if (value > value2)
            vect.push_back(std::make_pair(value,value2));
        else
            vect.push_back(std::make_pair(value2,value));
        argc -=2;
    }
    int last;
    if (single)
        last = value_parser(*argv);

    for (int i = 0; i < (int)vect.size(); i++)
    {
        std::cout << i << ": " <<vect[i].first << std::endl;
        std::cout << i << ": "<< vect[i].second << std::endl;
    }
        std::cout << last << std::endl;    
}