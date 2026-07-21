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

void PmergeMe::sort_vect_jahnson(bool single, int last)
{
    std::vector<int> mainChain;
    std::vector<int> pend;
    
    for (size_t i = 0; i < _vect.size(); i++)
    {
        mainChain.push_back(_vect[i].first); 
        pend.push_back(_vect[i].second);    
    }

    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    int jPrev = 1;
    int jCurr = 3;
    int pend_size = pend.size();
    std::vector<int>::iterator bound;
    std::vector<int>::iterator pos;
    
    while (jPrev < pend_size)//21 30
    {
        int end = std::min(jCurr, pend_size) - 1;//43-30
        int start = jPrev;//21

        for (int i = end; i >= start; i--)
        {
            bound = std::find(mainChain.begin(), mainChain.end(), _vect[i].first);
            pos = std::lower_bound(mainChain.begin(), bound, pend[i]);
            mainChain.insert(pos, pend[i]);
        }
        int next = jCurr + 2 * jPrev;
        jPrev = jCurr;
        jCurr = next;
    }
    if (single)
    {
        pos = std::lower_bound(mainChain.begin(), mainChain.end(), last);
        mainChain.insert(pos, last);
    }
    for (size_t i = 0; i < mainChain.size(); i++)
        std::cout << mainChain[i] << " ";
}

void PmergeMe::_parser(int argc,char **argv)
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
            _vect.push_back(std::make_pair(value,value2));
        else
            _vect.push_back(std::make_pair(value2,value));
        argc -=2;
    }

    int last ;
    if (single)
        last = value_parser(*argv);
    sort_vector(_vect);
    sort_vect_jahnson(single,last);
}

void PmergeMe::sort_vector(std::vector< std::pair<int, int> > &_vect)
{
    if (_vect.size() <= 1)
        return;

    int mid = _vect.size() / 2;
    std::vector< std::pair<int, int> > left(_vect.begin(), _vect.begin() + mid);
    std::vector< std::pair<int, int> > right(_vect.begin() + mid, _vect.end());

    sort_vector(left);
    sort_vector(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].first <= right[j].first)
            _vect[k++] = left[i++];
        else
            _vect[k++] = right[j++];
    }

    while (i < left.size()) 
        _vect[k++] = left[i++];
    while (j < right.size()) 
     _vect[k++] = right[j++];
}

void PmergeMe::run(int argc,char **argv)
{
    _parser(argc,argv);

}