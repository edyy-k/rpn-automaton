#include <iostream>
#include <ctype.h>
#include <chrono>
#include <thread>

#include "Stack.h"

using namespace std;

void doStep(Stack stack)
{
    stack.printStack();
    this_thread::sleep_for(chrono::seconds(1));
}

bool validate(const string &input, bool stepMode)
{
    Stack stack;

    for (char c : input)
    {
        // put every integer on the stack
        if (isdigit(c))
        {
            stack.push((int)c - '0');
            if (stepMode)
                doStep(stack);
            continue;
        }

        try
        {
            switch (c)
            {
            case ' ': // ignore spaces
                continue;
                break;
            case '+': // do addition
                stack.push(stack.pop() + stack.pop());
                if (stepMode)
                    doStep(stack);
                break;
            case '*': // do multiplication
                stack.push(stack.pop() * stack.pop());
                if (stepMode)
                    doStep(stack);
                break;
            default: // any other characters will cause a fail state
                return false;
                break;
            }
        }
        catch (exception &e)
        {
            return false;
        }
    }

    // Land on a fail state if there are more than one integer in the stack
    if (stack.size() != 1)
        return false;

    printf("Result: %d\n", stack.pop());

    return true;
}

int main(int argc, char *argv[])
{
    bool stepMode = false;

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        if (arg == "--step-mode")
            stepMode = true;
    }

    string line;
    while (getline(cin, line))
    {
        cout << "Validating {" << line << "}..." << endl;

        bool result = validate(line, stepMode);

        cout << "> " << (result ? "ACCEPTED" : "REJECTED") << endl
             << endl;
    }

    return 0;
}
