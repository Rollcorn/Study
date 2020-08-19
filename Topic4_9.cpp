#include <iostream>
#include <vector>
#include <string>

//Глава 4: 
//Задача 9: Отслеживает сумму введенных значений (помимо наименьшего и
//наибольшего значений) и их количество. По завершению цикла выводит на
//экран наименьшее, наибольшее, количество значений и сумму. 

void enter_numbers(std::vector<double>* vr, 
                   std::vector<std::string>* vu){
                   
    constexpr double cm_per_m = 100;
    constexpr double in_per_m = 39.3701;
    constexpr double ft_per_m = 3.2808;    
    double max_elem;
    double min_elem;
    double temp;
    double sum = 0;
    int count = 0;
    
    std::string unit;
    while(std::cin >> temp >> unit){
        if(temp == '|') break;    
        std::cout << temp << unit << std::endl;
        if(unit == "cm") temp = temp/cm_per_m;
        else if(unit == "in") temp = temp/in_per_m;
        else if(unit == "ft") temp = temp/ft_per_m;        
        else if(unit == "m") {temp = temp;}
        else {std::cout << "Invalid Unit\n\n";
              continue;};
        count += 1;
        sum += temp;    
        vr->push_back(temp);
        vu->push_back(unit);
        
        std::cout << "Current number: " << temp << "\n";
        std::cout << "Current counter of numbers: " << count << "\n"; 
        std::cout << "Current summ of numbers: " << sum << "m" << "\n\n";
        if(vr->size() != 1){
            if(max_elem < temp){
               max_elem = temp;
               std::cout << "Current MAX number is:  " << max_elem <<
                                                     "m\n\n";
            };
            if(min_elem > temp){
                min_elem = temp;
                std::cout << "Current MIN number is: " << min_elem <<
                                                     "m\n\n";
        }else{ max_elem = temp;
               min_elem = temp;
        };
        };
    }
}

int main()
{
    std::vector<double> vec_n;
    std::vector<std::string> vec_u;

    std::cout<<"Enter some numbers and unit: ";
    enter_numbers(&vec_n, &vec_u);
        
    std::cout << "The list of numbers: ";
    for(int i=0; i<vec_n.size();i++){
        std::cout << vec_n[i] << "m" << " ";
    };
    std::cout << "\n";
    return 0;
};

