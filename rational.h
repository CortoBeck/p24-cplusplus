#pragma once

#include <stdexcept>
#include <iostream>

class Rational {
private:
    int num;
    int denom;

    friend Rational operator+(const Rational &r1, const Rational &r2);
    friend bool operator==(const Rational &r1, const Rational &r2);

public:
    Rational() : num(0), denom(1) {}

    Rational(int n) : num(n), denom(1) {}

    Rational(int n, int d) : num(n), denom(d) {
        if (denom == 0) {
            throw std::invalid_argument("Le dénominateur ne peut pas être nul.");
        }
    }

    void print() const {
        std::cout << num << "/" << denom << std::endl;
    }

    operator float() const {
        return static_cast<float>(num) / static_cast<float>(denom);
    }
};

Rational operator+(const Rational &r1, const Rational &r2) {
    int new_num = r1.num * r2.denom + r2.num * r1.denom;
    int new_denom = r1.denom * r2.denom;
    return Rational(new_num, new_denom);
}

bool operator==(const Rational &r1, const Rational &r2) {
    return (r1.num * r2.denom == r2.num * r1.denom);
}