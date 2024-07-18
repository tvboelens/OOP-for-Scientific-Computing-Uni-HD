#include <iostream>
#include <vector>
#include "rational.cpp"

int main()
{
    Rational f1{-3, 12};
    Rational f2{4, 3};

    std::cout << "f1 = ";
    f1.print_number();
    std::cout << "\n";

    std::cout << "f2 = ";
    f2.print_number();
    std::cout << "\n";

    std::cout << "f1+f2 = ";
    (f1 + f2).print_number();
    std::cout << "\n";

    std::cout << "f1*f2 = ";
    (f1 * f2).print_number();
    std::cout << "\n";

    std::cout << "4+f2 = ";
    (4 + f2).print_number();
    std::cout << "\n";

    std::cout << "f2+5 = ";
    (f2 + 5).print_number();
    std::cout << "\n";

    std::cout << "12*f1 = ";
    (12 * f1).print_number();
    std::cout << "\n";

    std::cout << "f1*6 = ";
    (f1 * 6).print_number();
    std::cout << "\n";

    std::cout << "f1/f2 = ";
    (f1 / f2).print_number();
    std::cout << "\n";

    std::vector<Rational> F;
    for (int i = 1; i < 7; ++i)
    {
        F = Farey(i);
        std::cout << "F_" << i << " = (";
        for (std::vector<Rational>::iterator i = F.begin(); i < F.end(); ++i)
        {
            i->print_number();
            std::cout << ", ";
        }
        std::cout << ")" << std::endl;
    }

    return 0;
}
