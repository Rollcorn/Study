#include <iostream>
#include <vector>
#include <string>

int max_numb(std::vector<int> v){  
    int max; 
    for(int i=0; i < v.size();i++){
        if(i==0) max = v[i];
        if(max < v[i]) max = v[i];
    };
    return max;
};

int min_numb(std::vector<int> v){  
    int min; 
    for(int i=0; i < v.size();i++){
        if(i==0) min = v[i];
        if(min > v[i]) min = v[i];     
    };
    return min;  
};

bool is_equal(std::vector<int> v){
    bool flag = false;  
    int tmp = v[0];
    for(int i=0; i < v.size();i++){
        if(v[i] != tmp) return false;
        else{
            tmp = v[i];
            flag = true;
        };     
    }
    return flag;
};

int main()
{
    int elem;
    std::vector<int> vr;
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
