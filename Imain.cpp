#include "I.h"

int main()
{
    toto::IntStack s1;
    s1.print();
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();                         // affichera [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affichera 3
    s1.print();                         // affichera [1 2 ]
    return 0;
}

//g++ -o main Imain.cpp I.cpp