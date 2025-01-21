#include "I.h"

namespace toto
{
    IntStack::IntStack(int s) : size(s), top(0), tab(new int[s]) {}

    IntStack::IntStack() : IntStack(SIZE) {}

    IntStack::~IntStack()
    {
        delete[] tab;
    }

    IntStack& IntStack::operator=(const IntStack& ri)
    {
        if (this != &ri)
        {
            delete[] tab;
            size = ri.size;
            top = ri.top;
            tab = new int[size];
            for (int i = 0; i < top; ++i)
            {
                tab[i] = ri.tab[i];
            }
        }
        return *this;
    }

    void IntStack::push(int e)
    {
        if (is_full())
        {
            std::cerr << "Erreur : La pile est pleine.\n";
        }
        else
        {
            tab[top++] = e;
        }
    }

    int IntStack::pop()
    {
        if (is_empty())
        {
            throw std::underflow_error("Erreur : La pile est vide.");
        }
        return tab[--top];
    }

    bool IntStack::is_empty() const
    {
        return top == 0;
    }

    bool IntStack::is_full() const
    {
        return top == size;
    }

    void IntStack::print() const
    {
        std::cout << '[';
        for (int i = 0; i < top; ++i)
        {
            std::cout << tab[i] << ' ';
        }
        std::cout << "[\n";
    }
}