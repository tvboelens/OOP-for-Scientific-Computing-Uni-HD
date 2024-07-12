#include "matrix.hh"
#include "vector.cc"
#include <iostream>


void Matrix::resize(int N,int M)
{
    entries.resize(N);
    for (size_t i = 0; i < entries.size();++i)
    {
        entries[i].resize(M);
    }
    m_numRows = N;
    m_numCols = M;
}

void Matrix::resize(int N, int M, double value)
{
    entries.resize(N);
    for (size_t i = 0; i < entries.size(); ++i)
    {
        entries[i].resize(M);
        for (size_t j = 0; j < entries[i].size();++j)
        {
            entries[i][j] = value;
        }
    }
    m_numRows = N;
    m_numCols = M;
}

void Matrix::resize(int N)
{
    entries.resize(N);
    for (size_t i = 0; i < entries.size(); ++i)
    {
        entries[i].resize(N);
    }
    m_numRows = N;
    m_numCols = N;
}

void Matrix::resize(int N, double value)
{
    entries.resize(N);
    for (size_t i = 0; i < entries.size(); ++i)
    {
        entries[i].resize(N);
        for (size_t j = 0; j < entries[i].size(); ++j)
        {
            entries[i][j] = value;
        }
    }
    m_numRows = N;
    m_numCols = N;
}

void Matrix::print() const
{
    std::cout << "(" << get_numRows() << "," << get_numCols() << ") matrix:" << std::endl;
    for (size_t i = 0; i < entries.size(); ++i)
    {
        for (size_t j = 0; j < entries[i].size();++j)
        {
            std::cout << entries[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Matrix::print(int i, bool print_row=true) const
{
    if (print_row)
    {
        std::cout << "Row " << i << " of (" << get_numRows()
                  << "," << get_numCols() << ") matrix" << "\n";
        for (size_t j = 0; j < entries[i].size(); ++j)
        {
            std::cout << entries[i][j] << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "Column " << i << " of (" << get_numRows()
                  << "," << get_numCols() << ") matrix" << "\n";
        for (int j = 0; j < get_numCols(); ++j)
        {
            std::cout << entries[j][i] << " ";
        }
        std::cout << "\n";
    }
}

double& Matrix::operator()(int i, int j)
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

double Matrix::operator()(int i, int j) const
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

std::vector<double>& Matrix::operator[](int i)
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

std::vector<double> Matrix::operator[](int i) const
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

Matrix& Matrix::operator+=(const Matrix &B)
{
    if(m_numRows!=B.get_numRows())
    {
        std::cerr << "Number of rows of matrix A (" << m_numRows
                  << ") and matrix B (" << B.get_numRows()
                  << ") do not match!";
        std::cerr << std::endl;
    }
    if (m_numCols != B.get_numCols())
    {
        std::cerr << "Number of columns of matrix A (" << m_numCols
                  << ") and matrix B (" << B.get_numCols()
                  << ") do not match!";
        std::cerr << std::endl;
    }
    for (int i = 0; i < m_numRows ;++i)
    {
        for (int j = 0; j < m_numCols; ++j)
        {
            entries[i][j] += B(i, j);
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(double x)
{
    for (int i = 0; i < m_numRows; ++i)
    {
        for (int j = 0; j < m_numCols; ++j)
        {
            entries[i][j] *=x;
        }
    }
    return *this;
}

Matrix operator+(const Matrix& A, const Matrix& B)
{
    Matrix output = Matrix(A);
    output += B;
    return output;
}

Matrix operator*(const Matrix& A, const double& x)
{
    Matrix output = Matrix(A);
    output *= x;
    return output;
}

Matrix operator*(const double& x, const Matrix& A)
{
    Matrix output = Matrix(A);
    output *= x;
    return output;
}

std::vector<double> operator*(const Matrix& A, const std::vector<double>& v)
{
    if (A.get_numCols()!=v.size())
    {
        std::cerr << "Number of columns of matrix A (" << A.get_numCols()
                  << ") and length of vector v (" << v.size()
                  << ") do not match!";
        std::cerr << std::endl;
    }
    std::vector<double> output = std::vector<double>(A.get_numRows());
    for (int i = 0; i < A.get_numRows(); ++i)
    {
        for (int j = 0; j < A.get_numCols();++j)
        {
            output[i] += A(i, j) * v[j];
        }
    }
    return output;
}

Vector operator*(const Matrix& A, const Vector& v)
{
    if (A.get_numCols() != v.size())
    {
        std::cerr << "Number of columns of matrix A (" << A.get_numCols()
                  << ") and length of vector v (" << v.size()
                  << ") do not match!";
        std::cerr << std::endl;
    }
    Vector output = Vector(A.get_numRows());
    for (int i = 0; i < A.get_numRows(); ++i)
    {
        for (int j = 0; j < A.get_numCols(); ++j)
        {
            output[i] += A(i, j) * v[j];
        }
    }
    return output;
}

Matrix operator-(const Matrix& A)
{
    Matrix output = Matrix(A);
    output *= -1.;
    return output;
}

Matrix operator-(const Matrix& A, const Matrix& B)
{
    return A + -B;
}
