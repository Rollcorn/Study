#include <iostream>
#include <vector>
#include <string>
//Глава 4: 
//Задача 4 Программа Топик4 для типов double.
//Задача 5 Программа сравнивает числа и говорит что они
//         равны если различаются на 1/100.

double max_numb(std::vector<double> v){  
    double max; 
    for(int i=0; i < v.size();i++){
        if(i==0) max = v[i];
        if(max < v[i]) max = v[i];
    };
    return max;
};

double min_numb(std::vector<double> v){  
    double min; 
    for(int i=0; i < v.size();i++){
        if(i==0) min = v[i];
        if(min > v[i]) min = v[i];     
    };
    return min;  
};

bool is_equal(std::vector<double> v){
    bool flag = false;  
    double tmp = v[0];
    for(int i=0; i < v.size();i++){
        double def;
        if(v[i] < tmp) def = tmp - v[i];
        else def = v[i] - tmp;
        if(def > 0.01) return false;
        else{
            tmp = v[i];
            flag = true;
        };     
    }
    return flag;
};

int main()
{
    double elem;
    std::vector<double> vr;
    std::cout<<"Enter some numbers: ";
    while(std::cin >> elem){
        if('|' != elem) vr.push_back(elem);
    };
    
    std::cout << "The list of numbers: ";
    for(int i=0; i<vr.size();i++){
        std::cout << vr[i]<< " ";
    };
    std::cout << "\n";
    
    if(is_equal(vr)==true){
        std::cout << "Numbers are equals\n";
    }else{
    std::cout << "Max number is: " << max_numb(vr) << std::endl;
    std::cout << "Min number is: " << min_numb(vr) << std::endl;
    }

return 0;
};
