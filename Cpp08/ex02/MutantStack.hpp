#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <deque>

// std::stack'ten public olarak miras alıyoruz
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // 1. Orthodox Canonical Form
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    ~MutantStack() {}
    
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T>::operator=(other); // Atama işlemini base class'a (std::stack) devrediyoruz
        }
        return *this;
    }

    // 2. Iterator Tanımlamaları (Typedef)
    // std::stack'in altındaki 'container_type'ın iteratörlerini kendi iteratörümüzmüş gibi tanımlıyoruz.
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // 3. Iterator Fonksiyonları
    // 'c', std::stack'in içindeki protected (korumalı) alt container'ın adıdır! 
    // Bu sayede içerdeki iteratörleri dışarıya açmış (expose etmiş) oluyoruz.
    
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif