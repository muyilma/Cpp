#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _array;
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
        void addNumber(T first, T second)
        {
            if (std::distance(first, second) + _array.size() > _N)
                throw std::out_of_range("Insufficient capacity!");
            
            _array.insert(_array.end(), first, second);
        }
};

#endif