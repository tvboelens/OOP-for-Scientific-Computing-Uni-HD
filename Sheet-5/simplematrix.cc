#include "simplematrix.hh"
#include "vector.cc"
#include <iostream>

template <typename T>
void SimpleMatrix<T>::resize(int N, int M)
{
    entries.resize(N);
    for (size_t i = 0; i < entries.size(); ++i)
    {
        entries[i].resize(M);
    }
    m_numRows = N;
    m_numCols = M;
}

template <typename T>
void SimpleMatrix<T>::resize(int N)
{
    entries.resize(N);
    for (size_t i = 0; i < entries.size(); ++i)
    {
        entries[i].resize(N);
    }
    m_numRows = N;
    m_numCols = N;
}

template <typename T>
void SimpleMatrix<T>::print() const
{
    std::cout << "(" << get_numRows() << "," << get_numCols() << ") matrix:" << std::endl;
    for (size_t i = 0; i < entries.size(); ++i)
    {
        for (size_t j = 0; j < entries[i].size(); ++j)
        {
            std::cout << entries[i][j] << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
void SimpleMatrix<T>::print(int i, bool print_row) const
{
    if (print_row)
    {
        std::cout << "Row " << i + 1 << " of (" << get_numRows()
                  << "," << get_numCols() << ") matrix" << "\n";
        for (size_t j = 0; j < entries[i].size(); ++j)
        {
            std::cout << entries[i][j] << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "Column " << i + 1  << " of (" << get_numRows()
                  << "," << get_numCols() << ") matrix" << "\n";
        for (int j = 0; j < get_numCols(); ++j)
        {
            std::cout << entries[j][i] << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
T& SimpleMatrix<T>::operator()(int i, int j)
{
    if (i < 0 || i >= m_numRows)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << get_numRows() - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= m_numCols)
    {
        std::cerr << "Illegal index " << j;
        std::cerr << " valid range is [0:" << get_numRows() - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i][j];
}

template <typename T>
T SimpleMatrix<T>::operator()(int i, int j) const
{
    if (i < 0 || i >= m_numRows)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << get_numRows() - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= m_numCols)
    {
        std::cerr << "Illegal index " << j;
        std::cerr << " valid range is [0:" << get_numRows() - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i][j];
}

template <typename T>
std::vector<T>& SimpleMatrix<T>::operator[](int i)
{
    if (i < 0 || i >= m_numRows)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << get_numRows() - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }

    return entries[i];
}

template <typename T>
std::vector<T> SimpleMatrix<T>::operator[](int i) const
{
    if (i < 0 || i >= m_numRows)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << get_numRows() - 1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }

    return entries[i];
}

template <typename T>
NumMatrix<T>& NumMatrix<T>::operator+=(const NumMatrix<T> &B)
{
    if (this->m_numRows != B.get_numRows())
    {
        std::cerr << "Number of rows of matrix A (" << this->m_numRows
                  << ") and matrix B (" << B.get_numRows()
                  << ") do not match!";
        std::cerr << std::endl;
    }
    if (this->m_numCols != B.get_numCols())
    {
        std::cerr << "Number of columns of matrix A (" << this->m_numCols
                  << ") and matrix B (" << B.get_numCols()
                  << ") do not match!";
        std::cerr << std::endl;
    }
    for (int i = 0; i < this->m_numRows; ++i)
    {
        for (int j = 0; j < this->m_numCols; ++j)
        {
            this->entries[i][j] += B(i, j);
        }
    }
    return *this;
}

template <typename T>
NumMatrix<T>& NumMatrix<T>::operator*=(T x)
{
    for (int i = 0; i < this->m_numRows; ++i)
    {
        for (int j = 0; j < this->m_numCols; ++j)
        {
            this->entries[i][j] *= x;
        }
    }
    return *this;
}

template <typename T>
NumMatrix<T> operator+(const NumMatrix<T> &A, const NumMatrix<T> &B)
{
    NumMatrix<T> output = NumMatrix<T>(A);
    output += B;
    return output;
}

template <typename T>
NumMatrix<T> operator*(const NumMatrix<T> &A, const T &x)
{
    NumMatrix<T> output = NumMatrix<T>(A);
    output *= x;
    return output;
}

template <typename T>
NumMatrix<T> operator*(const T &x, const NumMatrix<T> &A)
{
    NumMatrix<T> output = NumMatrix<T>(A);
    output *= x;
    return output;
}

template <typename T>
std::vector<T> operator*(const NumMatrix<T> &A, const std::vector<T> &v)
{
    if (A.get_numCols() != v.size())
    {
        std::cerr << "Number of columns of matrix A (" << A.get_numCols()
                  << ") and length of vector v (" << v.size()
                  << ") do not match!";
        std::cerr << std::endl;
    }
    std::vector<T> output = std::vector<T>(
        static_cast<size_t>(A.get_numRows()), static_cast<T>(0));
    for (int i = 0; i < A.get_numRows(); ++i)
    {
        for (int j = 0; j < A.get_numCols(); ++j)
        {
            output[i] += A(i, j) * v[j];
        }
    }
    return output;
}

template <typename T>
Vector<T> operator*(const NumMatrix<T> &A, const Vector<T> &v)
{
    if (A.get_numCols() != v.size())
    {
        std::cerr << "Number of columns of matrix A (" << A.get_numCols()
                  << ") and length of vector v (" << v.size()
                  << ") do not match!";
        std::cerr << std::endl;
    }
    Vector<T> output = Vector<T>{A.get_numRows(), 0};
    for (int i = 0; i < A.get_numRows(); ++i)
    {
        for (int j = 0; j < A.get_numCols(); ++j)
        {
            output[i] += A(i, j) * v[j];
        }
    }
    return output;
}

template <typename T>
NumMatrix<T> operator-(const NumMatrix<T> &A)
{
    NumMatrix<T> output = NumMatrix<T>(A);
    T x = -1;
    output *= x;
    return output;
}

template <typename T>
NumMatrix<T> operator-(const NumMatrix<T> &A, const NumMatrix<T> &B)
{
    return A + -B;
}
