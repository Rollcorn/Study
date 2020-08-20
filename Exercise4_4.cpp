#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//Глава 4 Упражнение 4: Программа угадывает число. Пользователь загадывает
//число от 1 до 100, а программа задает вопросы, чтобы выяснить какое 
//число он задумал.

void guess_number(uint16_t lower_bound, uint16_t upper_bound){
    std::string guess;
    std::string answr;
    std::cout << "Your number is less than " << 
                (upper_bound+lower_bound)/2 << "? \n";
    std::cin >> answr;
    if(answr == "y"){ //if get yes - number less than upper_bound/2;
        upper_bound = (upper_bound + lower_bound)/2;

    }else if(answr == "n"){
        lower_bound = (upper_bound + lower_bound)/2;
    };
    std::cout << "You guess " << (upper_bound+lower_bound)/2 
                                  << " ?\n";
    std::cin >> guess;
 
    if(guess == "yes" || guess == "y" || guess == "Yes") 
        std::cout <<  (upper_bound + lower_bound)/2 << "\n";
    else if(guess == "n" || guess == "no" || guess == "No") {
        guess_number(lower_bound, upper_bound);};
};     



int main(){
    std::string answr;
    uint16_t upper_bound;
    uint16_t lower_bound;
    std::cout << "Enter guessing range: \n";
    std::cin >> lower_bound >> upper_bound;
    std::cout << "Guess the number from " << lower_bound << 
                  " to " << upper_bound  << std::endl;
    
    guess_number(lower_bound, upper_bound);    


return 0;
}

