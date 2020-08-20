#include <iostream>

//Глава 4 Упражнение 5: Программа выполняет простейшие функции калькулятора
//+, -, *, :. Программа предлагает пользователю ввести 3 аргументы - 2 пере-
//менные и оператор.

void result(int16_t arg_1, int16_t arg_2, char op){ 
    int16_t result;
    switch(op){
    case '+':
        result = arg_1 + arg_2;
        std::cout << "The sum of " << arg_1 << " and " << arg_2 
                  << " is: " << result << std::endl;
        break;
    case '-':
        result = arg_1 - arg_2;
        std::cout << "The differences of " << arg_1 << " and " << arg_2 
                  << " is:  " << result << std::endl;
        break;
    case '*':
        result = arg_1 * arg_2;
        std::cout  << "The product of " << arg_1 << " and " << arg_2 
                  << " is: " << result << std::endl;
        break;
    case ':':
        result = arg_1 / arg_2;
        std::cout << "The division result of " << arg_1 << " and " << arg_2 
                  << " is: " << result << std::endl;
        break;
    }
};

int main(){
    int16_t first_arg;
    int16_t second_arg;
    char oper;

    std::cout << "Please enter the first argument: ";
    std::cin >> first_arg;
    std::cout << "Please enter the second argument: ";
    std::cin >> second_arg;
    std::cout << "Please enter the operator: ";
    std::cin >> oper;
  
    result(first_arg, second_arg, oper); 

    return 0;
}

