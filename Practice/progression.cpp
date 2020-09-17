#include <iostream>
#include <vector>

/*Прогрессия: 1 2 4 ... Шахматная доска 8 * 8. 
* Программа вычисляет сколько клеток надо заполнить, чтобы получить НЕ 
* МЕНЕЕ 1000, 1000 000, 1000 000 000.
* Использовать цикл, несколько переменных int для отслеживания номера
* клетки, количество зерен в текущей и предыдущих клетках.
* Выводить на экран значение всех этих переменных на каждой итерации.
*/
using std::cout;
using std::endl;
using std::cin;
using std::vector;
const int DESK_SIZE = 64;

void progression(long int desire_prize){
    long int curr_prize = 1;
    vector<long int> desk_prize {curr_prize};
    for(int i = 0; i < DESK_SIZE; i++){
        if(curr_prize/2 < desire_prize){
            curr_prize *= 2;
            desk_prize.push_back(curr_prize);
            cout << "Position #" << i << '\t';
            cout << desk_prize[i] << endl;
        }
    }
}


int main(){
   cout << "Enter your desire prise: " << endl;
   int desire_prise;
   cin >> desire_prise; 
   cout << "The prise on the desk is: \n";
   progression(desire_prise);

return 0;
}
