#include <vector>
#ifndef Stack_H
#define Stack_H

class Stack
{
private:
    std::vector<int> stack;

public:
    int pop();
    void push(const int n);
    void printStack();
    size_t size();
};

#endif
