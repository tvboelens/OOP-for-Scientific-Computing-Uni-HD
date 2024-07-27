#ifndef NUMERICAL_INTEGRATION_HH
#define NUMERICAL_INTEGRATION_HH

#include <vector>

class Function
{
    public:
        virtual double operator()(double x) const = 0;
};

class Quadrature
{
    public:
        virtual double fit(double left_endpoint, double right_endpoint) const = 0;
        Quadrature(const Function &function) : m_func{&function} {};
    protected:
        const Function* m_func;
};

class Integral
{
    public:
        void fit(int num_subintervals = 0);
        double evaluate() const;
        void setInterval(double left_endpoint, double right_endpoint)
        {
            m_left_endpoint = left_endpoint;
            m_right_endpoint = right_endpoint;
        }
        Integral(const Function &func, const Quadrature &quad,
                 double left_endpoint, double right_endpoint)
            : m_func{&func}, m_quad{&quad}, m_left_endpoint{left_endpoint}, m_right_endpoint{right_endpoint} {};

    private:
        const Function* m_func;
        const Quadrature* m_quad;
        double m_left_endpoint;
        double m_right_endpoint;
        std::vector<double> subintegrals;
};

#endif
