#ifndef RATIONAL_HH
#define RATIONAL_HH

#include <iostream>
#include <vector>
#include <cassert>

int gcd(int x, int y);

class Rational
{
private:
    int m_numerator{1};
    int m_denominator{1};

public:
    // Arithmetic operations
    Rational &operator+=(const Rational &p);
    Rational &operator*=(const Rational &p);

    // Constructors
    Rational() {};
    Rational(int numerator, int denominator);
    Rational(int integer)
        : m_numerator{integer}, m_denominator{1} {};
    Rational(const Rational &p)
        : Rational{p.get_numerator(), p.get_denominator()} {};
    // Access and print functions
    const int &get_denominator() const { return m_denominator; }
    const int &get_numerator() const { return m_numerator; }
    void print_number() { std::cout << get_numerator() << "/" << get_denominator(); }
};

Rational operator+(const Rational &p, const Rational &q);

Rational operator+(const Rational &p, const int &k);

Rational operator-(const Rational &p);

Rational operator-(const Rational &p, const Rational &q);

Rational operator-(const Rational &p, const int &k);

Rational operator*(const Rational &p, const Rational &q);

Rational operator*(const Rational &p, const int &k);

Rational operator/(const Rational &p, const Rational &q);

Rational operator/(const Rational &p, const int &k);

bool operator<(const Rational &p, const Rational &q);

std::vector<Rational> Farey(int n);

std::ostream& operator<<(std::ostream &str, const Rational &r);

#endif
