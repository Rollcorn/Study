#include <iostream>
#include <cmath>

void calculate(double a, double b, double c){
    double x1, x2;
    double D = b*b - 4*a*c;
    if(D >= 0){
        x1 = (-b + (std::sqrt(D)))/(2*a);
        x2 = (-b - (std::sqrt(D)))/(2*a);
    }else{
        std::cout << "The answer are complex!" << std::endl;
        
    }
    std::cout << "Answer: x1 = " << x1 << ", x2 = " << x2 << std::endl;
}

int main(){
    double a, b, c;
    std::cout << std::sqrt(4.);
    std::cout << "Enter your numbers: a, b, c" << std::endl;
    std::cin >> a >> b >> c;
    calculate(a, b, c); 

return 0;
}
