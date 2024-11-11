#include <iostream>

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 12;
    int b = 81;
    swap(a, b);
    // ici, a == 81 et b == 12
    std::cout << "a = " << a << ", b = " << b << std::endl;
}