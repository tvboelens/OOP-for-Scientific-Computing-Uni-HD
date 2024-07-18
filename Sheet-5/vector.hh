#ifndef VECTOR_HH
#define VECTOR_HH

#include <vector>

template <typename T>
class Vector
{
public:
    void resize(int N_);
    void resize(int N_, T value);
    // access elements
    T& operator()(int i);
    T operator()(int i) const;
    T& operator[](int i);
    T operator[](int i) const;
    // arithmetic functions
    Vector<T>& operator*=(T x);
    Vector<T>& operator+=(const Vector<T>& b);
    // output
    void print() const;
    int size() const
    {
        return N;
    }

    Vector<T>(int N_) : entries(N_), N(N_) {};

    Vector<T>(int N_, T value)
    {
        resize(N_, value);
    };

    Vector<T>(std::vector<T> v)
    {
        N = v.size();
        entries = v;
    }
    

    Vector<T>(const Vector<T>& v)
    {
        N = v.N;
        entries = v.entries;
    }

private:
    std::vector<T> entries;
    int N = 0;
};

template <typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b);
template <typename T>
Vector<T> operator*(const Vector<T>& a, T x);
template <typename T>
Vector<T> operator*(T x, const Vector<T>& a);
template <typename T>
T operator*(const Vector<T>& a, const Vector<T>& b);

#endif // VECTOR_HH
