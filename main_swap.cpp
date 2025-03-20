#include <iostream>
#include "swap.h"

int main() {
    int x = 10, y = 20;

    std::cout << "Avant swap (pointeurs) : x = " << x << ", y = " << y << std::endl;
    swap(&x, &y);
    std::cout << "Après swap (pointeurs) : x = " << x << ", y = " << y << std::endl;

    int a = 42, b = -15;
    std::cout << "Avant swap (références) : a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "Après swap (références) : a = " << a << ", b = " << b << std::endl;

    return 0;
}