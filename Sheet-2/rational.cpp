#include <iostream>

int gcd(int x, int y)
{
    int largest, smallest, remainder;
   
    if (x > y)
    {
        largest = x;
        smallest = y;
    }
    else 
    {
        largest = y;
        smallest = x;
    }
    while (smallest>0)
    {
        remainder = largest % smallest;
        largest = smallest;
        smallest = remainder;
    }
    return largest;
}



int main()
{
    int a, b;
    std::cout << "Eingabe a,b für gcd(a,b)";
    std::cin >> a >> b;
    std::cout << "gcd(a,b) = " << gcd(a, b) << std::endl;
    return 0;
}
