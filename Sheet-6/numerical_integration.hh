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
        virtual double fit(double left_endpoint, double right_endpoint) = 0;
        Quadrature(const Function &function) : m_func{&function} {};
    protected:
        const Function* m_func;
};

class Integral
{
    public:
        double fit(int num_subintervals = 0);
        Integral(const Function& func, const Quadrature& quad,
                 int left_endpoint, int right_endpoint, int num_subintervals)
            : m_func{&func}
            , m_quad{&quad}
            , m_left_endpoint{left_endpoint}
            , m_right_endpoint{right_endpoint}
            , subintegrals(num_subintervals, 0.) {};

    private:
        const Function* m_func;
        const Quadrature* m_quad;
        const double m_left_endpoint;
        const double m_right_endpoint;
        std::vector<double> subintegrals;
};

#endif
