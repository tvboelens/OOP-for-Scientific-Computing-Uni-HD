#include "vector.hh"
#include <iomanip>
#include <iostream>
#include <cstdlib>

template <typename T>
void Vector<T>::resize(int N_)
{
    entries.resize(N_);
    N = N_;
}

template <typename T>
void Vector<T>::resize(int N_, T value)
{
    entries.resize(N_);
    for (size_t i = 0; i < entries.size(); ++i)
    {
        entries[i] = value;
    }
    N = N_;
}

template <typename T>
T& Vector<T>::operator()(int i)
{
    if (i < 0 || i >= N)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << N - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}

template <typename T>
T Vector<T>::operator()(int i) const
{
    if (i < 0 || i >= N)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << N - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}

template <typename T>
T& Vector<T>::operator[](int i)
{
    if (i < 0 || i >= N)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << N - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}

template <typename T>
T Vector<T>::operator[](int i) const
{
    if (i < 0 || i >= N)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << N - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}

template <typename T>
Vector<T>& Vector<T>::operator*=(T x)
{
    for (int i = 0; i < N; ++i)
        entries[i] *= x;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector &b)
{
    const int M = b.N;
    if (b.N != N)
    {
        std::cerr << "Dimensions of vector a (" << N
                  << ") and vector b (" << b.N
                  << ") do not match!";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; ++i)
        entries[i] += b[i];
    return *this;
}

template <typename T>
void Vector<T>::print() const
{
    std::cout << "(" << N << ") vector:" << std::endl;
    for (int i = 0; i < N; ++i)
    {
        std::cout << std::setprecision(3);
        std::cout << std::setw(5) << entries[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
{
    Vector<T> output(a);
    output += b;
    return output;
}

template <typename T>
Vector<T> operator*(const Vector<T>& v, T x)
{
    Vector<T> output(v);
    output *= x;
    return output;
}

template <typename T>
Vector<T> operator*(T x, const Vector<T>& v)
{
    Vector<T> output(v);
    output *= x;
    return output;
}

template <typename T>
T operator*(const Vector<T>& a, const Vector<T>& b)
{
    const int N = a.size();
    if (b.size() != N)
    {
        std::cerr << "Dimensions of vector a (" << N
                  << ") and vector b (" << b.size()
                  << ") do not match!";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    T scalprod = a(0)*b(0);
    for (int i = 1; i < N; ++i)
        scalprod += a(i) * b(i);
    return scalprod;
}
