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
        std::cout << (*v)[i] << " ";
    }
};

double find_mediana(std::vector<double>* v){
    double mediana;
    int fir;
    if(((v->size()) % 2) == 0){
        fir = ((v->size()-1)/2);
        return ((*v)[fir]+(*v)[fir+1])/2;
    
    }else{
        return (*v)[(v->size()/2)]; 
    }; 
};
 
int main(){

std::vector<double> vec;

fill_up_vec(&vec);

std::sort(vec.begin(), vec.end());

std::cout << "Sorted vector: " << std::endl;
print_vec(&vec);
std::cout << std::endl;

std::cout << "Mediana is: " << find_mediana(&vec) << std::endl;

return 0;
}

