#include "numerical_integration.hh"
#include <numeric>
#include <list>
#include <vector>
#include <iostream>

class Trapezoidal: public Quadrature
{
    public:
        virtual double fit(const double& a, const double& b, const double& f_a, const double& f_b) const override
        {
            double Q = {(f_a+f_b)/2};
            Q *= (b - a);
            return Q;
        }
        Trapezoidal(const Function &func) : Quadrature{func} {};
};

class Simpson : public Quadrature
{
    public:
        virtual double fit(const double &a, const double &b, const double &f_a, const double &f_b) const override
        {
            double midpoint{(a + b) / 2};
            double Q{f_a + 4*m_func->operator()(midpoint) + f_b};
            Q *= (b - a) / 6;
            return Q;
        }
        Simpson(const Function &func) : Quadrature{func} {};
};

void Integral::setInterval(double left_endpoint, double right_endpoint)
{
    m_interval_endpoints = std::list<double>{left_endpoint};
    m_function_values = std::list<double>{m_func->operator()(left_endpoint)};
    if (m_num_intervals != 0)
    {
        for (int i = 1; i < m_num_intervals; ++i)
        {
            m_interval_endpoints.push_back(
                left_endpoint + (right_endpoint - left_endpoint) * i / m_num_intervals);
            m_function_values.push_back(
                m_func->operator()(left_endpoint + (right_endpoint - left_endpoint) * i / m_num_intervals));
        }
    }
    m_interval_endpoints.push_back(right_endpoint);
    m_function_values.push_back(m_func->operator()(right_endpoint));
}

void Integral::setNumSubintervals(int n)
{
    m_num_intervals = n;
    double left_endpoint = m_interval_endpoints.front();
    double right_endpoint = m_interval_endpoints.back();
    setInterval(left_endpoint, right_endpoint);
}

void Integral::fit(float error)
{
    if (m_num_intervals!=0)
    {
        subintegrals.clear();
        std::list<double>::iterator it_endpoints{m_interval_endpoints.begin()};
        std::list<double>::iterator it_values{m_function_values.begin()};
        while (subintegrals.size()<m_num_intervals)
        {
            subintegrals.push_back(m_quad->fit(
                *it_endpoints, *std::next(it_endpoints),
                *it_values, *std::next(it_values) ));
            ++it_endpoints;
            ++it_values;
        }
    }
    /* else
    {
        subintegrals.resize(1, m_quad->fit(m_left_endpoint, m_right_endpoint));
        size_t i{0};
        while (i<subintegrals.size())
        {
            
        }
        
    } */
}

double Integral::evaluate() const
{
    double integral = std::accumulate(subintegrals.begin(), subintegrals.end(), 0.0);
    return integral;
}
