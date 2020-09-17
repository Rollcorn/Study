#include <iostream>
#include <vector>
#include <string>

//Глава 4 Упражнение 6: Создать вектор, хранящий десять строковых значений 0
//-9. Сделать функцию преобразующую введенное число в строковое значение и
// наоборот.

std::string  int_to_str(int num){
    std::vector<std::string> numers = {"zero", "one", "two", "three", 
                     "four", "five", "six", "seven", "eight", "nine"};
    return numers[num];


}



int main(){
    
    int num;
    std::cin >> num;
    std::cout << "Transformed number from integer to string: " 
              << int_to_str(num) << std::endl;


   return 0;
}

