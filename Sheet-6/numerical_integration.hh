#ifndef NUMERICAL_INTEGRATION_HH
#define NUMERICAL_INTEGRATION_HH

#include <vector>
#include <list>

class Function
{
    public:
        virtual double operator()(double x) const = 0;
};

class Quadrature
{
    public:
        virtual double fit(const double& a, const double& b, const double& f_a, const double& f_b) const = 0;
        Quadrature(const Function &function) : m_func{&function} {};
    protected:
        const Function* m_func;
};

class Integral
{
    public:
        void fit(float eps = 0.05);
        double evaluate() const;
        void setInterval(double left_endpoint, double right_endpoint);
        void setNumSubintervals(int n);
        Integral(const Function &func, const Quadrature &quad,
                 double left_endpoint, double right_endpoint, int num_subintervals = 0)
            : m_func{&func}
            , m_quad{&quad}
            , m_num_intervals{num_subintervals}
            {
                setInterval(left_endpoint, right_endpoint);
            };

    private:
        const Function* m_func;
        const Quadrature* m_quad;
        int m_num_intervals;
        std::list<double> m_interval_endpoints;
        std::list<double> m_function_values;
        std::list<double> subintegrals;
};

#endif
