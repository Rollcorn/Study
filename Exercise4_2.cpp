#include <iostream>
#include <vector>
#include <algorithm>

//Глава 4 Упражнение 2: Определить медиану вектора дабл.

void fill_up_vec(std::vector<double>* v){
    std::cout << "Enter the numbers: " << "\n";
    for(double number; std::cin >> number;){
        if('|' == number) break;
        v->push_back(number);
    }
};

void print_vec(std::vector<double>* v){
    for(int i = 0; i < (v->size()); i++){
        std::cout << (*v)[i] << std::endl;
    }
};

double find_mediana(std::vector<double>* v){
    double mediana;
    int first, second;
    if((v->size() % 2) == 0){
        first = (v->size()/2);
        second = first + 1;
//        std::cout << (*v)[first] << " "  << (*v)[second]
  //                                       << std::endl;   
        return mediana = (((*v)[first]+(*v)[second])/2);
    
    }else{
        return (mediana = (*v)[(v->size()/2)]);
        };
};

int main(){

std::vector<double> vec;

fill_up_vec(&vec);

std::sort(vec.begin(), vec.end());

print_vec(&vec);

double m = 25/2;
std::cout << m << std::endl;
std::cout << "Mediana is: " << find_mediana(&vec);


return 0;
}

