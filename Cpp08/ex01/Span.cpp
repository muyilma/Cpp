#include "Span.hpp"

Span::Span()
{ 
    _N = 0;
}

Span::Span(unsigned int n)
{
    _N = n;
}

Span::Span(const Span& other)
{
    this->_N = other._N;
    this->_array = other._array;
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_N = other._N;
        this->_array = other._array;
    }
    return *this;
    
}

void Span::addNumber(int number) {
    if (_array.size() >= _N) 
        throw std::out_of_range("Index out of bounds!");
    _array.push_back(number);
}

int Span::shortestSpan()
{
    if (_array.size() < 2)
        throw std::out_of_range("Index out of bounds!");

    std::vector<int> copy = _array;
    std::sort(copy.begin(), copy.end());

    int min_span = copy[1] - copy[0];
    for (size_t i = 1; i < copy.size() - 1; i++)
    {
        int diff = copy[i + 1] - copy[i];
        if (diff < min_span)
            min_span = diff;
    }
    
    return min_span;
}

int Span::longestSpan()
{
    if (_array.size() < 2)
        throw std::out_of_range("Index out of bounds!");

    int min_val = *std::min_element(_array.begin(), _array.end());
    int max_val = *std::max_element(_array.begin(), _array.end());

    return max_val - min_val;
}
