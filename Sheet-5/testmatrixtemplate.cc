#include "matrix.cc"
#include <iostream>
#include <complex>
#include "../Sheet-2/rational.cpp"

int main()
{
    std::cout << "Testing type int...\n";
    Matrix<int> A(2, 3);
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
    Matrix<int> B(2, 3);
    B = A + A;
    B.print();
    B = A - A;
    B.print();
    A.print();
    std::vector<int> v;
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
    std::vector<int> w;
    w = A * v;
    std::cout << "A * v = ";
    for (size_t i = 0; i < w.size(); ++i)
    {
        std::cout << w[i] << " ";
        }
    std::cout << "\n";

    Vector<int> x(v);
    //x.print();
    Vector<int> y(A.get_numRows());
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
    std::cout << "Testing printing of columns:\n";
    Matrix<int> C(3);
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

    std::cout << "Testing type double...\n";
    Matrix<double> A_d(2, 3);
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
    Matrix<double> B_d(2, 3);
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
    Matrix<double> C_d(3);
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

    std::cout << "Testing type complex...\n";
    Matrix<std::complex<double>> A_c(2, 3);
    std::complex<double> z{0, 1};
    for (int i = 0; i < A_c.get_numRows(); ++i)
    {
        for (int j = 0; j < A_c.get_numCols(); ++j)
        {
            A_c(i, j) = std::complex<double>{i*1.,0} + std::complex<double>{j*1.,0} + std::pow(z,i+j);
        }
    }
    A_c.print();
    A_c *= 2;
    A_c.print();
    Matrix<std::complex<double>> B_c(2, 3);
    B_c = A_c + A_c;
    B_c.print();
    B_c = A_c - A_c;
    B_c.print();
    A_c.print();
    std::vector<std::complex<double>> v_c;
    v_c.resize(3);
    for (size_t i = 0; i < v_c.size(); ++i)
    {
        v_c[i] += std::pow(z,i) + std::complex<double>{1,0};
    }
    std::cout << "v = ";
    for (size_t i = 0; i < v_c.size(); ++i)
    {
        std::cout << v_c[i] << " ";
    }
    std::cout << "\n";
    std::vector<std::complex<double>> w_c;
    w_c = A_c * v_c;
    std::cout << "A * v = ";
    for (size_t i = 0; i < w_c.size(); ++i)
    {
        std::cout << w_c[i] << " ";
    }
    std::cout << "\n";

    Vector<std::complex<double>> x_c(v_c);
    // x.print();
    Vector<std::complex<double>> y_c(A_c.get_numRows());
    y_c.print();
    y_c = A_c * x_c;
    y_c.print();
    std::cout << "\n";
    std::cout << "A * v = ";
    for (int i = 0; i < y_c.size(); ++i)
    {
        std::cout << y_c[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Testing printing of columns:\n";
    Matrix<std::complex<double>> C_c(3);
    for (int i = 0; i < C_c.get_numRows(); ++i)
    {
        for (int j = 0; j < C_c.get_numCols(); ++j)
        {
            C_c(i, j) = std::complex<double>{i*1., 0} + std::complex<double>{j*1., 0} + std::pow(z, i + j);
        }
    }
    C_c.print();
    for (size_t i = 0; i < C_c[1].size(); ++i)
    {
        std::cout << C[1][i] << " ";
    }
    std::cout << "\n";
    C_c.print(1);
    C_c.print(2, false);

    y_c = C_c * x_c;
    y_c.print();

    std::cout << "Testing type Rational...\n";
    Matrix<Rational> A_r(2, 3);
    for (int i = 0; i < A_r.get_numRows(); ++i)
    {
        for (int j = 0; j < A_r.get_numCols(); ++j)
        {
            A_r(i, j) = Rational{i+1,j+1};
        }
    }
    A_r.print();
    
    A_r *= Rational{3};

    A_r.print();

    Matrix<Rational> B_r(2, 3);
    B_r = A_r + A_r;
    B_r.print();
    B_r = A_r - A_r;
    B_r.print();
    A_r.print();
    std::vector<Rational> v_r;
    v_r.resize(3);
    for (int i = 0; i < v_r.size(); ++i)
    {
        v_r[i] = Rational{1,i + 1};
    }
    std::cout << "v = ";
    for (size_t i = 0; i < v_r.size(); ++i)
    {
        std::cout << v_r[i] << " ";
    }
    std::cout << "\n";
    std::vector<Rational> w_r;
    w_r = A_r * v_r;
    std::cout << "A * v = ";
    for (size_t i = 0; i < w_r.size(); ++i)
    {
        std::cout << w_r[i] << " ";
    }
    std::cout << "\n";

    Vector<Rational> x_r(v_r);
    // x.print();
    Vector<Rational> y_r(A_r.get_numRows());
    std::cout << "(" << y_r.size()
              << ") vector :\n";
    for (int i = 0; i < y_r.size();++i)
    {
        std::cout << y_r[i] << " ";
    }
    std::cout << std::endl;
    y_r = A_r * x_r;
    y_r.print();
    std::cout << "\n";
    std::cout << "A * v = ";
    for (int i = 0; i < y_r.size(); ++i)
    {
        std::cout << y_r[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Testing printing of columns:\n";
    Matrix<Rational> C_r(3);
    for (int i = 0; i < C_r.get_numRows(); ++i)
    {
        for (int j = 0; j < C_r.get_numCols(); ++j)
        {
            C_r(i, j) = Rational{i, j + 1};
        }
    }
    C_r.print();
    for (size_t i = 0; i < C_r[1].size(); ++i)
    {
        std::cout << C_r[1][i] << " ";
    }
    std::cout << "\n";
    C_r.print(1);
    C_r.print(2, false);
    C_r.print();
    x_r.print();
    y_r = C_r * x_r;

    y_r.print();

    return 0;
}
