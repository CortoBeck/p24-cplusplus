#pragma once
#include <iostream>
#include <stdexcept>

const int SIZE{12};

class IntStack
{
public:
    IntStack() : top(0), size(SIZE) {}

    void push(int e)
    {
        if (is_full())
        {
            throw std::overflow_error("La pile est pleine");
        }
        tab[top] = e;
        top++;
    }

    int get_top()
    {
        if (is_empty())
        {
            throw std::underflow_error("La pile est vide");
        }
        return tab[top - 1];
    }

    int pop()
    {
        if (is_empty())
        {
            throw std::underflow_error("La pile est vide");
        }
        top--;
        return tab[top];
    }

    bool is_empty() const
    {
        return top == 0;
    }

    bool is_full() const
    {
        return top == size;
    }

    void print() const
    {
        std::cout << '[';
        for (int i = 0; i < top; i++)
        {
            std::cout << tab[i] << ' ';
        }
        std::cout << ']' << std::endl;
    }

private:
    int tab[SIZE];
    int top;
    int size;
};