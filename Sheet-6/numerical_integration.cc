#include "numerical_integration.hh"

class Trapezoidal: public Quadrature
{
    virtual double fit(double left_endpoint, double right_endpoint)
    {
        double Q = {m_func->operator()(left_endpoint) + m_func->operator()(right_endpoint)};
        Q *= (right_endpoint - left_endpoint)/2;
        return Q;
    }
};

class Simpson : public Quadrature
{
    virtual double fit(double left_endpoint, double right_endpoint)
    {
        double midpoint{(left_endpoint + right_endpoint) / 2};
        double Q{m_func->operator()(left_endpoint) + 4*m_func->operator()(midpoint) + m_func->operator()(right_endpoint)};
        Q *= (right_endpoint - left_endpoint) / 6;
        return Q;
    }
};
