#include <iostream>

class Rational
{
private:
    int num;
    int denom;

public:
    Rational() : num(0), denom(1)
    {
    }

    Rational(int n) : num(n), denom(1) {}

    Rational(int n, int d) : num(n), denom(d)
    {
        if (denom == 0)
        {
            std::cout << "Erreur: Le dénominateur ne peut pas être nul." << std::endl;
            denom = 1;
        };
    }

    void print() const
    {
        std::cout << num << "/" << denom << std::endl;
    }

    // Opérateur global ==
    friend bool operator==(const Rational &r1, const Rational &r2)
    {
        return (r1.num * r2.denom == r2.num * r1.denom);
    }

    // Opérateur global +
    friend Rational operator+(const Rational &r1, const Rational &r2)
    {
        int new_num = r1.num * r2.denom + r2.num * r1.denom;
        int new_denom = r1.denom * r2.denom;
        return Rational(new_num, new_denom);
    }


    // Opérateur de conversion en float
    operator float() const
    {
        return static_cast<float>(num) / static_cast<float>(denom);
    }
};

int main()
{

    Rational r1;
    Rational r2(1);
    Rational r3(4, 6);
    Rational r4(1, 2);
    Rational r5 = r3 + r4;
    std::cout << r3 << " + " << r4 << " = " << r5 << std::endl;
    return 0;
}
