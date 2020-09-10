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
const int desk_row = 8;
const int desk_colum = 8;

int progression(int desire_prise){
    int r;
    int c;
    int desk_size = desk_row * desk_colum;
    int* desk = new int[desk_row];
    for(int i = 0; i < desk_row; i++){
        *desk[i] = new int[desk_colum];
        for(int j = 0; j < desk_colum; j++){
            if(i == 0 && j == 0) desk[i][j] = 1;
            else desk[i][j] *= 2;  
            if(desk[i][j] >= desire_prise){
                cout << desk[i][j];
                r = i;
                c = j;
                break;               
            }else  cout << desk[i][j];
        }
    }

    delete[] desk;
    return r, c;
}

int main(){
   cout << "Enter your desire prise: " << endl;
   int desire_prise;
   cin >> desire_prise; 
   cout << "The prise on the desk is: " << progression(desire_prise)
                                        << endl;


return 0;
}
