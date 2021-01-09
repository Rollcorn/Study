#include <iostream>
//Функция ищет в массиве строку с минимальным элементом массива и меняет ей с первой
void swap_min(int *m[], unsigned rows, unsigned cols)
 {
    int min_row;
    int min_elem;
    for(int i = 0; i != rows; i++){
        for(int j = 0; j != cols; j++){
            if(i == 0 && j == 0){
                 min_elem = m[0][0];
             }else{ 
                 if (min_elem > m[i][j]){
                     min_elem = m[i][j];
                     min_row = i;
                 }
             }
         }
     }
    int* tmp = m[0];
    m[0] = m[min_row];
    m[min_row] = tmp;
 }


int main(){



    return 0;
}
