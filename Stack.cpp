#include "Stack.h"
#include <iostream>

using namespace std;

int Stack::pop()
{
    if (stack.empty())
    {
        throw runtime_error("Trying to pop from an empty stack.");
    }

    int popElement = stack.front();
    stack.erase(stack.begin());

    return popElement;
}

void Stack::push(const int n)
{
    stack.insert(stack.begin(), n);
}

void Stack::printStack()
{
    cout << "[";

    for (auto it = stack.begin(); it != stack.end(); ++it)
    {
        int &element = *it;

        cout << element;

        if (it != prev(stack.end()))
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

size_t Stack::size()
{
    return stack.size();
}
