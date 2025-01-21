#include <iostream>
#include <stdexcept>

// Constante pour la taille par défaut de la pile
const int SIZE = 12;

class IntStack
{
public:
    // Constructeur avec taille personnalisée
    IntStack(int s) : size(s), top(0), tab(new int[s])
    {
        
    }

    // Constructeur par défaut
    IntStack() : IntStack(SIZE) {}

    // Destructeur
    ~IntStack()
    {
        delete[] tab; 
    }

    IntStack& operator=(const IntStack& ri)
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

   
    void push(int e)
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

    
    int pop()
    {
        if (is_empty())
        {
            throw std::underflow_error("Erreur : La pile est vide.");
        }
        return tab[--top];
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
        for (int i = 0; i < top; ++i)
        {
            std::cout << tab[i] << ' ';
        }
        std::cout << "]" << std::endl;
    }

private:
    int* tab;  
    int size;
    int top;
};

int main()
{
    IntStack s1;
    s1.print();
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();                         // affichera [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affichera 3
    s1.print();                         // affichera [1 2 ]
    return 0;
}