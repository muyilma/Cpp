#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class PmergeMe
{
    private:    
        void _parser(int argc,char **argv);

        std::vector<std::pair<int, int> > _vect;
        std::deque<std::pair<int, int> > _deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        

        int value_parser(char *argv);
        void run(int argc,char **argv);
        
        void sort_vector(std::vector< std::pair<int, int> > &_vect);
        void sort_vect_jahnson(bool single, int last);
        
        void sort_deque(std::deque< std::pair<int, int> > &_vect);
        void sort_deq_jahnson(bool single, int last);
};

#endif