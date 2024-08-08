#include <iostream>
#include <vector>
#include <cassert>
#include "rational.hh"

int gcd(int x, int y)
{
    if (x==0|y==0)
    {
        return 1;
    }
    int largest, smallest, remainder;
    /* Use absolute value if x or y are negative. 
    Euclidean algorithm requires us to know which number is larger.*/
    if (std::abs(x) > std::abs(y))
    {
        largest = std::abs(x);
        smallest = std::abs(y);
    }
    else 
    {
        largest = std::abs(y);
        smallest = std::abs(x);
    }
    // Implementation of Euclidean algorithm
    while (smallest>0)
    {
        remainder = largest % smallest;
        largest = smallest;
        smallest = remainder;
    }
    return largest;
}


Rational& Rational::operator+=(const Rational& p)
{
    int temp_denominator{m_denominator * p.get_denominator()};
    int temp_numerator{m_denominator * p.get_numerator() + m_numerator * p.get_denominator()};
    int d = gcd(temp_denominator, temp_numerator);
    m_denominator = temp_denominator / d;
    m_numerator = temp_numerator / d;
    return *this;
}
        
Rational& Rational::operator *=(const Rational& p)
{
    int d{gcd(m_denominator * p.get_denominator(), m_numerator * p.get_numerator())};
    m_numerator *= p.get_numerator();
    m_numerator /= d;
    m_denominator *= p.get_denominator();
    m_denominator /= d;
    return *this;
}
        
Rational::Rational(int numerator, int denominator)
    : m_denominator{denominator / gcd(denominator, numerator)}
    , m_numerator{numerator / gcd(denominator, numerator)}
{
    if (m_denominator==0)
    {
        throw std::runtime_error("Denominator cannot be 0");
    }
    if  (m_denominator<0)
    {
        m_denominator *= -1;
        m_numerator *= -1;
    }
    if (m_numerator==0)
    {
        m_denominator = 1;
    }
}




Rational operator+(const Rational& p, const Rational& q)
{
    Rational output{p};
    output += q;
    return output;
}

Rational operator+(const Rational& p, const int& k)
{
    return p + Rational{k, 1};
}

Rational operator-(const Rational& p)
{
    return Rational{-p.get_numerator(), p.get_denominator()};
}

Rational operator-(const Rational& p, const Rational& q)
{
    return p + -q;
}

Rational operator-(const Rational& p, const int& k)
{
    return p - Rational{k};
}

Rational operator*(const Rational& p, const Rational& q)
{
    Rational output{p};
    output *= q;
    return output;
}

Rational operator*(const Rational& p, const int& k)
{
    return p*Rational{k};
}

Rational operator/(const Rational& p, const Rational& q)
{
    return Rational{p.get_numerator() * q.get_denominator(),
                    p.get_denominator() * q.get_numerator()};
}

Rational operator/(const Rational& p, const int& k)
{
    return p / Rational{1, k};
}

bool operator<(const Rational& p, const Rational& q)
{
    return (q - p).get_numerator() > 0;
}

std::vector<Rational> Farey(int n)
{
    std::vector<Rational> F = {Rational(0), Rational(1)};
    if(n==1) {
        return F;
    }
    // Determine Farey sequence recursively
    for (unsigned int k = 2; k <= n; k++)
    {
        std::vector<Rational>::iterator e = F.end();
        for (std::vector<Rational>::iterator m = F.begin(); m < (e-1); ++m)
        {
            if (m -> get_denominator() + (m + 1) -> get_denominator() == k)
            {
                m = F.insert(m + 1, Rational{m -> get_numerator() + (m + 1) -> get_numerator(),
                                             m -> get_denominator() + (m + 1) -> get_denominator()});
                e = F.end();//Insertion might have shifted e, so we need to reinitialize it.
            }
        }
    }
        return F;
}

std::ostream &operator<<(std::ostream &str, const Rational &r)
{
    str << r.get_numerator() << "/" << r.get_denominator();
    return str;
}
