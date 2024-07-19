#ifndef SIMPLEMATRIX_HH
#define SIMPLEMATRIX_HH

#include <vector>

template <typename T>
class SimpleMatrix
{
protected:
    int m_numRows{0};
    int m_numCols{0};
    std::vector<std::vector<T>> entries;

public:
    void resize(int N, int M);
    void resize(int N);
    // access functions
    T &operator()(int i, int j);
    T operator()(int i, int j) const;
    std::vector<T> &operator[](int i);
    std::vector<T> operator[](int i) const;
    // output
    void print() const;
    void print(int i, bool print_row = true) const;
    const int &get_numRows() const { return m_numRows; }
    const int &get_numCols() const { return m_numCols; }
    const std::vector<std::vector<T>> &get_entries() const { return entries; }

    // Constructors
    SimpleMatrix(int numRows, int numCols)
        : m_numRows{numRows}, m_numCols{numCols}, entries(numRows)
    {
        for (size_t i = 0; i < entries.size(); ++i)
        {
            entries[i].resize(numCols);
        }
    };

    SimpleMatrix(int N)
        : m_numRows{N}, m_numCols{N}, entries(N)
    {
        for (size_t i = 0; i < entries.size(); ++i)
        {
            entries[i].resize(N);
        }
    };

    SimpleMatrix(const SimpleMatrix<T> &A)
        : m_numRows{A.get_numRows()}, m_numCols{A.get_numCols()}, entries{A.get_entries()} {};
};

template <typename T>
class NumMatrix: public SimpleMatrix<T>
{
    public:
    // arithmetic functions
    NumMatrix &operator*=(T x);
    NumMatrix &operator+=(const NumMatrix &B);
    // Constructors
    NumMatrix(int numRows, int numCols)
        : SimpleMatrix<T>{numRows, numCols} {};

    NumMatrix(int N)
        : SimpleMatrix<T>{N} {};

    NumMatrix(const NumMatrix<T> &A)
        : SimpleMatrix<T>{A} {};
};

#endif
