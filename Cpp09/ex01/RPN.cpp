#include "RPN.hpp"

RPN::RPN()
{ 
}

RPN::RPN(const RPN& other)
{
    this->stack = other.stack;
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& other)
{
    if(this != &other)
    {
        this->stack = other.stack;
    }
    return *this;
}

void RPN::calculate(const std::string& str)
{
    if(str.empty())
        throw std::runtime_error("Error");

    int i = 0;
    while(str[i])
    {
        if(str[i] == ' ')
        {
            i++;
            continue;
        }
        if(((str[i] >= '0' && str[i] <= '9' ) || str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') && !(str[i + 1] != ' ' && str[i + 1] != '\0'))
        {
            if (str[i] >= '0' && str[i] <= '9')
                stack.push(str[i] - '0');
            else
            {
                if (stack.size() < 2)
                 throw std::runtime_error("Error");
                
                int n1 = stack.top();
                stack.pop();
                int n2 = stack.top();
                stack.pop();

                if (str[i] == '*')
                    stack.push(n2 * n1);
                else if (str[i] == '+')
                    stack.push(n2 + n1);
                else if (str[i] == '-')
                    stack.push(n2 - n1);
                else if (str[i] == '/')
                {
                    if (n1 == 0)
                     throw std::runtime_error("division by zero");
                    stack.push(n2 / n1);
                }
            }
            i++;
        }
        else
            throw std::runtime_error("Error");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << stack.top() << std::endl;
}