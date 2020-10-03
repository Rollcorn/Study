#include <iostream>
#include "Timer.cpp"

//The programm sums up the elem of two demension matrix (int) by columns 
//and by rows. Measure work time  
const static int MAX_COLUMNS = 100;
const static int MAX_ROWS = 100;
using namespace std;

void matrix_fill(int matrix[MAX_COLUMNS][MAX_ROWS]){
    int col_numb;
    int row_numb;
    int number;
    cout << "Please enter numbers of columns: " << endl;
    cin >> col_numb;
    cout << "Please enter numbers of rows: "  << endl;
    cin >> row_numb;
    for(int j = 0; j != row_numb ; j++){
        for(int i = 0; i != col_numb; i++){
            cout << "Enter some number: " << endl;
            cin >> number;
            matrix[i][j] = number;
        }
    }
    for(int j; j != row_numb ; j++){
        for(int i; i != col_numb; i++){
            cout << matrix[i][j] << endl; 
        }
    }

}

int main(){
    int matrix_1[MAX_COLUMNS][MAX_ROWS];
    int matrix_2[MAX_COLUMNS][MAX_ROWS];
        
    matrix_fill(matrix_1);
    matrix_fill(matrix_2);

return 0;
}
