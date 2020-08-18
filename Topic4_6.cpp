#include <iostream>
#include <vector>
#include <string>
//Глава 4: 
//Задача 6 Считывает по одному числу типа double в каждой итерации
//и определяет наименьшее и наибольшее значение среди всех ранее
//введенных значений

void enter_numbers(std::vector<double> vr){
    double max_elem;
    double min_elem;
    std::cout<<"Enter some numbers: ";
    for(double temp; std::cin >>  temp;){
        std::cout << temp << std::endl;
        if(!vr.empty()){
            if(max_elem < temp){
               max_elem = temp;
               std::cout << "Наибольшее число: " << max_elem <<
                                                     std::endl;
            }
            if(min_elem > temp){
                min_elem = temp;
                std::cout << "Наименьшее число: " << min_elem <<
                                                     std::endl;
        }else{ max_elem = temp;
               min_elem = temp;
        };
        vr.push_back(temp);
        };
    }
}

int main()
{
    std::vector<double> vec;
    enter_numbers(vec);
        
    std::cout << "The list of numbers: ";
    for(int i=0; i<vec.size();i++){
        std::cout << vec[i]<< " ";
    };
    std::cout << "\n";
   


    return 0;
};
