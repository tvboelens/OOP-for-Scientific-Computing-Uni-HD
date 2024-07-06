#include <iostream>

int gcd(int x, int y)
{
    int largest, smallest, remainder;
   
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
    while (smallest>0)
    {
        remainder = largest % smallest;
        largest = smallest;
        smallest = remainder;
    }
    return largest;
}

class Rational
{
    private:
        int m_numerator{};
        int m_denominator {};
    public:
        Rational()
            : m_numerator{1} , m_denominator{1}
        {
            /* std::cout << "Rational " << m_numerator << 
            "/" << m_denominator << " constructed \n"; */
        };
        Rational(int numerator, int denominator)
            : m_denominator{denominator / gcd(denominator, numerator)},
              m_numerator{numerator / gcd(denominator, numerator)}
        {
            if  (m_denominator<0)
            {
                m_denominator *= -1;
                m_numerator += -1;
            }
            //std::cout << "Rational " << m_numerator << "/" << m_denominator << " constructed \n";
        };
        Rational(int integer)
            : m_numerator{integer}, m_denominator{1}
        {
            /* std::cout << "Rational " << m_numerator
                      << "/" << m_denominator << " constructed \n"; */
        };
        int get_denominator() const { return m_denominator; }
        int get_numerator() const { return m_numerator; }
};

Rational operator+(const Rational& p, const Rational& q)
{
    return Rational{
        p.get_denominator()*q.get_numerator() + p.get_numerator()*q.get_denominator(), 
        p.get_denominator()*q.get_denominator()};
}

Rational operator+(const Rational& p, const int& k)
{
    return p + Rational{k, 1};
}

Rational operator-(const Rational& p)
{
    return Rational{-p.get_numerator(), p.get_numerator()};
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
    return Rational{p.get_numerator() * q.get_numerator(),
                    p.get_denominator() * q.get_denominator()};
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

int main()
{
    Rational f1{ -3, 12 };
    Rational f2{4, 3};

    std::cout << "f1+f2 = " << (f1 + f2).get_numerator() <<"/" << (f1+f2).get_denominator() << "\n";
    std::cout << "f1*f2 = " << (f1*f2).get_numerator() << "/" << (f1*f2).get_denominator() << "\n";
    std::cout << "4+f2 = " << (4 + f2).get_numerator() << "/" << (4 + f2).get_denominator() << "\n";
    std::cout << "f2+5 = " << (f2+5).get_numerator() << "/" << (f2+5).get_denominator() << "\n";
    std::cout << "12*f1 = " << (12*f1).get_numerator() << "/" << (12*f1).get_denominator() << "\n";
    std::cout << "f1*6 = " << (f1*6).get_numerator() << "/" << (f1*6).get_denominator() << "\n";
    std::cout << "f1/f2 = " << (f1 / f2).get_numerator() << "/" << (f1 / f2).get_denominator() << "\n";

    return 0;
}
