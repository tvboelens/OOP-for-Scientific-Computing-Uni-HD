#include "numerical_integration.cc"
#include <iostream>
#include <numbers>
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

class Sine: public Function
{
    public:
        double operator()(double x) const override
        {
            double output{std::sin(x)};
            output *= (x * std::numbers::inv_pi);
            return output;
        }
};

class SineIntegrated : public Function
{
public:
    double operator()(double x) const override
    {
        double output{std::sin(x) - x * std::cos(x)};
        output *= std::numbers::inv_pi;
        return output;
    }
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
    for (int i = 1; i <=20;++i)
    {
            IS.setNumSubintervals(i); // Something is wrong, for num_subintervals = 1 the answer is correct, but not for > 1
            IS.fit();
            IT.setNumSubintervals(i);
            IT.fit();
            std::cout << "num_subintervals = " << i << "\n";
            std::cout << "True integral = " << q(13) - q(-3) << "\n";
            std::cout << "Integral according to Simpson method = " << IS.evaluate() << "\n";
            std::cout << "Integral according to trapezoidal method = " << IT.evaluate() << "\n";
    }

    IS.setNumSubintervals(0); // Something is wrong, for num_subintervals = 1 the answer is correct, but not for > 1
    IS.fit();
    IT.setNumSubintervals(0);
    IT.fit();
    std::cout << "Using adptive integration...\n";
    std::cout << "True integral = " << q(13) - q(-3) << "\n";
    std::cout << "Integral according to Simpson method = " << IS.evaluate() << "\n";
    std::cout << "Integral according to trapezoidal method = " << IT.evaluate() << "\n";

    Sine f;
    SineIntegrated F;
    double n{20};
    
    Simpson QS_sine{f};
    Trapezoidal QT_sine{f};
    Integral IS_sine{f, QS_sine, 0.0, 2 * std::numbers::pi};
    Integral IT_sine{f, QT_sine, 0.0, 2 * std::numbers::pi};
    for (int i = 1; i <= 20; ++i)
    {
        IS_sine.setNumSubintervals(i); // Something is wrong, for num_subintervals = 1 the answer is correct, but not for > 1
        IS_sine.fit();
        IT_sine.setNumSubintervals(i);
        IT_sine.fit();
        std::cout << "num_subintervals = " << i << "\n";
        std::cout << "True integral = " << F(2*std::numbers::pi) - F(0) << "\n";
        std::cout << "Integral according to Simpson method = " << IS_sine.evaluate() << "\n";
        std::cout << "Integral according to trapezoidal method = " << IT_sine.evaluate() << "\n";
    }

    IS_sine.setNumSubintervals(0); // Something is wrong, for num_subintervals = 1 the answer is correct, but not for > 1
    IS_sine.fit(1e-5);
    IT_sine.setNumSubintervals(0);
    IT_sine.fit(1e-5);
    std::cout << "Using adptive integration...\n";
    std::cout << "True integral = " << F(2 * std::numbers::pi) - F(0) << "\n";
    std::cout << "Integral according to Simpson method = " << IS_sine.evaluate() << "\n";
    std::cout << "Integral according to trapezoidal method = " << IT_sine.evaluate() << "\n";
    return 0;
    return 0;
}
