#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

bool RPN::isOperator(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::processOperator(char op) {
    if (_stack.size() < 2)
        throw InvalidExpressionException();
    
    int b = _stack.back();
    _stack.pop_back();
    int a = _stack.back();
    _stack.pop_back();
    
    switch (op) {
        case '+':
            _stack.push_back(a + b);
            break;
        case '-':
            _stack.push_back(a - b);
            break;
        case '*':
            _stack.push_back(a * b);
            break;
        case '/':
            if (b == 0)
                throw DivisionByZeroException();
            _stack.push_back(a / b);
            break;
    }
}

int RPN::calculate(const std::string &expression)
{
    char c;
    _stack.clear();
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token.length() != 1)
            throw InvalidExpressionException();
        c = token[0];
        if (isdigit(c))
        {
            int num = c - '0';
            if (num >= 10)
                throw InvalidExpressionException();
            _stack.push_back(num);
        }
        else if (isOperator(c)) 
            processOperator(c);
        else
            throw InvalidExpressionException();
    }
    if (_stack.size() != 1)
        throw InvalidExpressionException();
    return _stack.back();
}

const char* RPN::InvalidExpressionException::what() const throw()
{
    return "Error: Invalid expression";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
    return "Error: Division by zero";
}