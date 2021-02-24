#include "Rational.hpp"

int main() { 
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3(5);

    r1.add(r2);
    std::cout << r1.to_double() << std::endl;
    r1.sub(r2);
    std::cout << r1.to_double() << std::endl;
    r1.neg();
    std::cout << r1.to_double() << std::endl;
    r3.mul(r1);
    std::cout << r3.to_double() << std::endl;
    r3.div(r2);
    std::cout << r3.to_double() << std::endl;
 
    r1 += r2;
    r1.print();
    std::cout << std::endl;
    r2 *= r2;
    r2.print();
    std::cout << std::endl;
    r1 /= r2;
    r1.print();
    std::cout << std::endl;
    r3 -= r1;
    r3.print();
    std::cout << std::endl;

 
 
}
