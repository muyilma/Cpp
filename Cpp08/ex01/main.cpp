#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try 
    {
        Span bigSp(10000);
        std::vector<int> numbers;
        
        for (int i = 0; i < 10000; ++i) 
        {
            numbers.push_back(i * 2); 
        }
        bigSp.addNumber(numbers.begin(), numbers.end());

        std::cout << "Shortest Span: " << bigSp.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << bigSp.longestSpan() << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
}