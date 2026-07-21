#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{ 
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    this->_vect = other._vect;
    this->_deq = other._deq;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_vect = other._vect;
        this->_deq = other._deq;
    }
    return *this;
}

void PmergeMe::sort_deque(std::deque< std::pair<int, int> > &_deq){
    if (_deq.size() <= 1)
        return;

    int mid = _deq.size() / 2;
    std::deque< std::pair<int, int> > left(_deq.begin(), _deq.begin() + mid);
    std::deque< std::pair<int, int> > right(_deq.begin() + mid, _deq.end());

    sort_deque(left);
    sort_deque(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].first <= right[j].first)
            _deq[k++] = left[i++];
        else
            _deq[k++] = right[j++];
    }

    while (i < left.size()) 
        _deq[k++] = left[i++];
    while (j < right.size()) 
     _deq[k++] = right[j++];
}

std::deque<int> PmergeMe::sort_deq_jahnson(bool single, int last){

 std::deque<int> mainChain;
    std::deque<int> pend;
    
    for (size_t i = 0; i < _deq.size(); i++)
    {
        mainChain.push_back(_deq[i].first); 
        pend.push_back(_deq[i].second);    
    }

    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    int jPrev = 1;
    int jCurr = 3;
    int pend_size = pend.size();
    std::deque<int>::iterator bound;
    std::deque<int>::iterator pos;
    
    while (jPrev < pend_size)
    {
        int end = std::min(jCurr, pend_size) - 1;
        int start = jPrev;

        for (int i = end; i >= start; i--)
        {
            bound = std::find(mainChain.begin(), mainChain.end(), _deq[i].first);
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
    return mainChain;
}

std::vector<int>  PmergeMe::sort_vect_jahnson(bool single, int last)
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
    
    while (jPrev < pend_size)
    {
        int end = std::min(jCurr, pend_size) - 1;
        int start = jPrev;

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
    return mainChain;
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

int PmergeMe::value_parser(char *argv)
{
    if (!argv || argv[0] == '\0')
        throw std::out_of_range("Error");
    for (int i = 0; argv[i] != '\0'; ++i) {
        if (!std::isdigit(argv[i]))
            throw std::out_of_range("Error");
    }
    long number = std::strtol(argv, NULL, 10);
    if (number < 0 || number > 2147483647)
        throw std::out_of_range("Error");
    return static_cast<int>(number);
}

void PmergeMe::run(int argc,char **argv)
{
    if (argc <= 1)
        throw std::out_of_range("Error");

    int tmp = argc;    
    bool single = false;
    int original_argc = argc - 1;

    argc--;
    if (!(argc % 2 == 0)) {
        single = true;
        argc--;
    }
    argv++;
    while (argc)
    {
        int value = value_parser(*argv++);
        int value2 = value_parser(*argv++);
        if (value > value2) {
            _vect.push_back(std::make_pair(value,value2));
            _deq.push_back(std::make_pair(value,value2));
        }
        else {
            _vect.push_back(std::make_pair(value2,value));
            _deq.push_back(std::make_pair(value2,value));
        }
        argc -=2;
    }

    int last ;
    if (single)
        last = value_parser(*argv);

    struct timeval start, end;
    long time_vect, time_deq;

    gettimeofday(&start, NULL);

    sort_vector(_vect);
    std::vector<int> sorted_vect = sort_vect_jahnson(single, last);
    
    gettimeofday(&end, NULL);  
    time_vect = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL); 
    
    sort_deque(_deq);
    std::deque<int> sorted_deq = sort_deq_jahnson(single, last);
    
    gettimeofday(&end, NULL);   
    time_deq = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
    std::cout << "Before: ";
    for (int i = 1; i < tmp; i++) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < sorted_vect.size(); i++) {
        std::cout << sorted_vect[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << original_argc << " elements with std::vector : " << time_vect << " us" << std::endl; 
    std::cout << "Time to process a range of " << original_argc << " elements with std::deque  : " << time_deq << " us" << std::endl;
}
