#include <iostream>
#include <vector>
#include <cassert>

int gcd(int x, int y)
{
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

class Rational
{
    private:
        int m_numerator {1};
        int m_denominator {1};
    public:
        Rational() {};
        Rational(int numerator, int denominator)
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
        };
        Rational(int integer)
            : m_numerator{integer}
            , m_denominator{1}
        {};
        const int& get_denominator() const { return m_denominator; }
        const int& get_numerator() const { return m_numerator; }
        void print_number() { std::cout << get_numerator() << "/" << get_denominator(); }
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

int main()
{
    Rational f1{ -3, 12 };
    Rational f2{4, 3};

    std::cout << "f1 = ";
    f1.print_number();
    std::cout << "\n";

    std::cout << "f2 = ";
    f2.print_number();
    std::cout << "\n";

    std::cout << "f1+f2 = ";
    (f1 + f2).print_number();
    std::cout << "\n";

    std::cout << "f1*f2 = ";
    (f1 * f2).print_number();
    std::cout << "\n";

    std::cout << "4+f2 = ";
    (4 + f2).print_number();
    std::cout << "\n";

    std::cout << "f2+5 = ";
    (f2 + 5).print_number();
    std::cout << "\n";

    std::cout << "12*f1 = ";
    (12 * f1).print_number();
    std::cout << "\n";

    std::cout << "f1*6 = ";
    (f1 * 6).print_number();
    std::cout << "\n";

    std::cout << "f1/f2 = ";
    (f1 / f2).print_number();
    std::cout << "\n";

    std::vector<Rational> F;
    for (int i = 1; i < 7;++i)
        {
            F = Farey(i);
            std::cout << "F_" << i << " = (";
            for (std::vector<Rational>::iterator i = F.begin(); i < F.end(); ++i)
            {
                i -> print_number();
                std::cout << ", ";
                }
            std::cout << ")" << std::endl;
        }

    return 0;
}
