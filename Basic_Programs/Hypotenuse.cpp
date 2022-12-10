#include <iostream>
#include <cmath>

int main()
{
    int base, height, hypo;
    std::cout << "Enter base of the rectangle: ";
    std::cin >> base;

    std::cout << "Enter height of triangle: ";
    std::cin >> height;

    std::cout << "Hypotenuse: " << sqrt(pow(base, 2) + pow(height, 2));
    return 0;
}