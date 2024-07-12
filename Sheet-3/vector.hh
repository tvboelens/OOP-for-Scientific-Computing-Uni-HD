#ifndef VECTOR_HH
#define VECTOR_HH

#include <vector>

class Vector
{
public:
    void resize(int N_);
    void resize(int N_, double value);
    // access elements
    double& operator()(int i);
    double operator()(int i) const;
    double& operator[](int i);
    double operator[](int i) const;
    // arithmetic functions
    Vector& operator*=(double x);
    Vector& operator+=(const Vector &b);
    // output
    void print() const;
    int size() const
    {
        return N;
    }

    Vector(int N_) : entries(N_), N(N_) {};

    Vector(int N_, double value)
    {
        resize(N_, value);
    };

    Vector(std::vector<double> v)
    {
        N = v.size();
        entries = v;
    }

    Vector(const Vector &v)
    {
        N = v.N;
        entries = v.entries;
    }

private:
    std::vector<double> entries;
    int N = 0;
};

Vector operator+(const Vector &a, const Vector &b);
Vector operator*(const Vector &a, double x);
Vector operator*(double x, const Vector &a);
double operator*(const Vector &a, const Vector &b);

#endif // VECTOR_HH
