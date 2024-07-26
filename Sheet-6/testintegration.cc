#include "numerical_integration.cc"
#include <iostream>
#include <vector>
#include <cmath>

class Polynomial: public Function
{
    public:
        double operator()(double x) const override
        {
            double output{m_coefficients[0]};
            for (size_t i = 1; i < m_coefficients.size();++i)
            {
                output += m_coefficients[i] * std::pow(x, i);
            }
            return output;
        }
        Polynomial(const std::vector<double> &coefficients) : m_coefficients{coefficients} {};

    private:
        std::vector<double> m_coefficients;
};

int main()
{
    std::vector<double> coefficients{5, 0, 2};
    std::vector<double> C{0,5, 0, 2./3.};
    Polynomial p{coefficients};
    Polynomial q{C};
    for (double x = -3; x <= 13; ++x)
    {
        std::cout << "p(" << x << ") = " << p(x)
                  << ". True value = " << 2* x * x + 5 << "\n";
    }
    Simpson QS{p};
    Trapezoidal QT{p};
    Integral IS{p, QS, -3.0, 13.0};
    Integral IT{p, QT, -3.0, 13.0};
    IS.fit(16);
    IT.fit(16);
    std::cout << "True integral = " << q(13) - q(-3) << "\n";
    std::cout << "Integral according to Simpson method = " << IS.evaluate() << "\n";
    std::cout << "Integral according to trapezoidal method = " << IT.evaluate() << "\n";
    return 0;
}
