#include "numerical_integration.hh"
#include <vector>
#include <iostream>

class Trapezoidal: public Quadrature
{
    public:
        virtual double fit(double left_endpoint, double right_endpoint) const override
        {
            double Q = {m_func->operator()(left_endpoint) + m_func->operator()(right_endpoint)};
            Q *= (right_endpoint - left_endpoint)/2;
            return Q;
        }
        Trapezoidal(const Function &func) : Quadrature{func} {};
};

class Simpson : public Quadrature
{
    public:
        virtual double fit(double left_endpoint, double right_endpoint) const override
        {
            double midpoint{(left_endpoint + right_endpoint) / 2};
            double Q{m_func->operator()(left_endpoint) + 4*m_func->operator()(midpoint) + m_func->operator()(right_endpoint)};
            Q *= (right_endpoint - left_endpoint) / 6;
            return Q;
        }
        Simpson(const Function &func) : Quadrature{func} {};
};

void Integral::fit(int num_subintervals)
{
    if (num_subintervals!=0)
    {
        subintegrals.resize(num_subintervals);
        for (size_t i = 0; i < subintegrals.size();++i)
        {
            subintegrals.at(i) = m_quad->fit(
                m_left_endpoint + 
                    (static_cast<double>(i) / num_subintervals) * (m_right_endpoint - m_left_endpoint),
                m_left_endpoint + 
                    ((static_cast<double>(i) + 1.) / num_subintervals) * (m_right_endpoint - m_left_endpoint));
        }
    }
}

double Integral::evaluate() const
{
    double integral{0};
    for (std::vector<double>::const_iterator it = subintegrals.begin(); it <= subintegrals.end(); ++it)
    {
        integral += *it;
    }
    return integral;
}
