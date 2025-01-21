#pragma once
#include <iostream>
#include <stdexcept>

namespace toto
{
    const int SIZE = 12;

    class IntStack
    {
    public:
        IntStack(int s);
        IntStack();
        ~IntStack();

        IntStack& operator=(const IntStack& ri);

        void push(int e);
        int pop();

        bool is_empty() const;
        bool is_full() const;

        void print() const;

    private:
        int* tab;
        int size;
        int top;
    };
}
