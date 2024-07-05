#include <iostream>

int gcd(int x, int y)
{
    int largest, smallest, remainder;
   
    if (x > y)
    {
        largest = x;
        smallest = y;
    }
    else 
    {
        largest = y;
        smallest = x;
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
        int m_denominator {};
        int m_numerator {};
    public:
        Rational()
            : m_denominator { 1 }, m_numerator { 1 }
            {
                std::cout << "Rational " << m_denominator
                          << "/" << m_numerator << "constructed \n";
            }
        Rational(int denominator, int numerator)
            : m_denominator { denominator/gcd(denominator, numerator) }, m_numerator { numerator/gcd(denominator, numerator) }
            {
                std::cout << "Rational " << m_denominator
                          << "/" << m_numerator << "constructed \n";
            }
        Rational(int integer)
            : m_denominator { integer }, m_numerator { 1 }
            {
                std::cout << "Rational " << m_denominator
                          << "/" << m_numerator << "constructed \n";
            }
};

int main()
{
    int a, b;
    std::cout << "Eingabe a,b für gcd(a,b)";
    std::cin >> a >> b;
    Rational q{ a, b };
    return 0;
}
