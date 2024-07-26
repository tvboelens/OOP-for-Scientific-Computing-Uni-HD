#include "numerical_integration.hh"
#include <vector>

class Trapezoidal: public Quadrature
{
    virtual double fit(double left_endpoint, double right_endpoint) const override
    {
        double Q = {m_func->operator()(left_endpoint) + m_func->operator()(right_endpoint)};
        Q *= (right_endpoint - left_endpoint)/2;
        return Q;
    }
};

class Simpson : public Quadrature
{
    virtual double fit(double left_endpoint, double right_endpoint) const override
    {
        double midpoint{(left_endpoint + right_endpoint) / 2};
        double Q{m_func->operator()(left_endpoint) + 4*m_func->operator()(midpoint) + m_func->operator()(right_endpoint)};
        Q *= (right_endpoint - left_endpoint) / 6;
        return Q;
    }
};

void Integral::fit(int num_subintervals)
{
    if (num_subintervals!=0)
    {
        double integral{0};
        subintegrals.resize(num_subintervals);
        for (size_t i = 0; i < subintegrals.size();++i)
        {
            subintegrals.at(i) = m_quad->fit(
                m_left_endpoint + i / num_subintervals,
                m_left_endpoint + (i + 1) / num_subintervals);
            integral += subintegrals[i];
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
