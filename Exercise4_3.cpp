#include <iostream>
#include <vector>
#include <algorithm>

//Глава 4 Упражнение 3: Считывает последовательность чисел типа double в
//вектор. Каждое значение представляет собой растояние между двумя 
//соседними городами. Вычисляет и выводит на печать общее расстояние,
//наименьшее, наибольшее и среднее расстояние между двумя соседними
//городами  

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

double avarage(std::vector<double>* v){
    double sum = 0;
    for(int i = 0; i < v->size(); i++)
        sum += (*v)[i];
    return sum/v->size();
};

double minimum(std::vector<double>* v){
    double min;
    for(int i = 0; i < v->size(); i++){
        if(i == 0) min = (*v)[i];
        else if(min > (*v)[i]) min = (*v)[i]; 
    };
    return min;
};

double maximum(std::vector<double>* v){
    double max;
    for(int i = 0; i < v->size(); i++){
        if(i == 0) max = (*v)[i];
        else if(max < (*v)[i]) max = (*v)[i];
    };
    return max;
};
     
int main(){

std::vector<double> vec;

fill_up_vec(&vec);

std::sort(vec.begin(), vec.end());

std::cout << "Sorted vector: " << std::endl;
print_vec(&vec);
std::cout << std::endl;

std::cout << "Avarage number is: " << avarage(&vec) << std::endl;

std::cout << "Minimum number is: " << minimum(&vec) << std::endl;

std::cout << "Maximum number is: " << maximum(&vec) << std::endl;

return 0;
}

