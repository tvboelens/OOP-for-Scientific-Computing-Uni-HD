#ifndef NUMERICAL_INTEGRATION_HH
#define NUMERICAL_INTEGRATION_HH

#include <vector>
#include <list>

class Function
{
    // Abstract base class for functions. Override () operator with the function definition.
    public:
        virtual double operator()(double x) const = 0;
};

class Quadrature
{
    // Abstract base class for quadrature. Stores a pointer to a Function object.
    // Fit method applies quadrature rule on [a,b] and additionally needs input f(a) and f(b).
    // We chose the input f(a) and f(b) since we will apply fit repeatedly to intervals which share
    // endpoints and we want to avoid evaluating f at the same points multiple times.
    public:
        virtual double fit(const double& a, const double& b, const double& f_a, const double& f_b) const = 0;
        Quadrature(const Function &function) : m_func{&function} {};
    protected:
        const Function* m_func;
};

class Integral
{
    // Class to calculate integral of a function based on a quadrature rule
    // If num_subintervals > 0, then the interval is subdivided into num_subintervals
    // subintervals of equal length and the quadrature rule is applied to each subinterval.
    // This is done using the fit method, the evaluate method returns the sum over all subintervals
    public:
        void fit(float eps = 0.05);
        double evaluate() const;
        void setInterval(double left_endpoint, double right_endpoint); // Changes the interval over which we integrate and calculates the subintervals
        void setNumSubintervals(int n);
        int getNumSubintervals() const;
        Integral(const Function &func, const Quadrature &quad,
                 double left_endpoint, double right_endpoint, int num_subintervals = 0)
            : m_func{&func}, m_quad{&quad}, m_num_intervals{num_subintervals}
        {
            setInterval(left_endpoint, right_endpoint);
            };

    private:
        const Function* m_func;
        const Quadrature* m_quad;
        int m_num_intervals;
        // For interval [a,b] on which we want to integrate, store a=t_0<t_1<...<t_n = b.
        // The fit method then applies quadrature to the interval [t_i, t_{i+1}].
        std::list<double> m_interval_endpoints; 
        std::list<double> m_function_values; // Stores f(t_i) to minimimize reevaluation of f.
        std::list<double> subintegrals; // Stores the results of the quadrature on each subinterval.
};

#endif
