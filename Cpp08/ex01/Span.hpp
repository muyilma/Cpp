#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> array;
    public:
        Span();
        ~Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
       
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();

        template <typename T>
        void addNumber(T first, T second);
};

#endif