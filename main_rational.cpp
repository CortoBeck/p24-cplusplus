#include <iostream>
#include "rational.h"

int main() {
    try {
        Rational r1;
        Rational r2(1);
        Rational r3(4, 6);
        Rational r4(1, 2);
        Rational r5 = r3 + r4;
        std::cout << r3 << " + " << r4 << " = " << r5 << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    return 0;
}