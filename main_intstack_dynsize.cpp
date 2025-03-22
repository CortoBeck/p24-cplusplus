#include "intstack_dynsize.h"

int main()
{
    toto::IntStack s1;
    s1.print();
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();
    std::cout << s1.pop() << std::endl;
    s1.print();
    return 0;
}