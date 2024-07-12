#include "matrix.cc"
#include <iostream>

int main()
{
    Matrix A(2, 3);
    for (int i = 0; i < A.get_numRows(); ++i)
    {
        for (int j = 0; j < A.get_numCols(); ++j)
        {
            A(i, j) = i + j + 1;
        }
    }
    A.print();
    A *= 2;
    A.print();
    Matrix B(2, 3);
    B = A + A;
    B.print();
    B = A - A;
    B.print();
    A.print();
    std::vector<double> v;
    v.resize(3);
    for (size_t i = 0; i < v.size(); ++i)
    {
        v[i] += i + 1.;
    }
    std::cout << "v = ";
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    std::vector<double> w;
    w = A * v;
    std::cout << "A * v = ";
    for (size_t i = 0; i < w.size(); ++i)
    {
        std::cout << w[i] << " ";
        }
    std::cout << "\n";

    Vector x(v);
    //x.print();
    Vector y(A.get_numRows());
    y.print();
    y = A * x;
    y.print();
    std::cout << "\n";
    std::cout << "A * v = ";
    for (int i = 0; i < y.size(); ++i)
    {
        std::cout << y[i] << " ";
    }
    std::cout << "\n";

    Matrix C(3);
    for (int i = 0; i < C.get_numRows(); ++i)
    {
        for (int j = 0; j < C.get_numCols(); ++j)
        {
            C(i, j) = i + j + 1;
        }
    }
    C.print();
    for (size_t i = 0; i < C[1].size(); ++i)
    {
        std::cout << C[1][i] << " ";
    }
    std::cout << "\n";
    C.print(1);
    C.print(2, false);

    y = C * x;
    y.print();

    return 0;
}
