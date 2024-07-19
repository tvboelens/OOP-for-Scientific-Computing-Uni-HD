#include "simplematrix.cc"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Testing SimpleMatrix and NumMatrix...\n";
    NumMatrix<double> A_d(2, 3);
    for (int i = 0; i < A_d.get_numRows(); ++i)
    {
        for (int j = 0; j < A_d.get_numCols(); ++j)
        {
            A_d(i, j) = i + j + 1;
        }
    }
    A_d.print();
    A_d *= 2;
    A_d.print();
    NumMatrix<double> B_d(2, 3);
    B_d = A_d + A_d;
    B_d.print();
    B_d = A_d - A_d;
    B_d.print();
    A_d.print();
    std::vector<double> v_d;
    v_d.resize(3);
    for (size_t i = 0; i < v_d.size(); ++i)
    {
        v_d[i] += i + 1.;
    }
    std::cout << "v = ";
    for (size_t i = 0; i < v_d.size(); ++i)
    {
        std::cout << v_d[i] << " ";
    }
    std::cout << "\n";
    std::vector<double> w_d;
    w_d = A_d * v_d;
    std::cout << "A * v = ";
    for (size_t i = 0; i < w_d.size(); ++i)
    {
        std::cout << w_d[i] << " ";
    }
    std::cout << "\n";

    Vector<double> x_d(v_d);
    // x.print();
    Vector<double> y_d(A_d.get_numRows());
    y_d.print();
    y_d = A_d * x_d;
    y_d.print();
    std::cout << "\n";
    std::cout << "A * v = ";
    for (int i = 0; i < y_d.size(); ++i)
    {
        std::cout << y_d[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Testing printing of columns:\n";
    NumMatrix<double> C_d(3);
    for (int i = 0; i < C_d.get_numRows(); ++i)
    {
        for (int j = 0; j < C_d.get_numCols(); ++j)
        {
            C_d(i, j) = i + j + 1;
        }
    }
    C_d.print();
    for (size_t i = 0; i < C_d[1].size(); ++i)
    {
        std::cout << C_d[1][i] << " ";
    }
    std::cout << "\n";
    C_d.print(1);
    C_d.print(2, false);

    y_d = C_d * x_d;
    y_d.print();
}
