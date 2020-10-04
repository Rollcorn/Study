#include <iostream>
#include "Timer.cpp"

//The programm sums up the elem of two demension matrix (int) by columns 
//and by rows. Measure work time  
const static int MAX_COLUMNS = 100;
const static int MAX_ROWS = 100;
using namespace std;

void matrix_fill(int matrix[MAX_ROWS][MAX_COLUMNS]){
    int col_numb;
    int row_numb;
    int number;
    cout << "Please enter numbers of columns: " << endl;
    cin >> row_numb;
    cout << "Please enter numbers of rows: "  << endl;
    cin >> col_numb;
    for(int j = 0; j != row_numb ; j++){
        for(int i = 0; i != col_numb; i++){
            cout << "Enter some number: " << endl;
            cin >> number;
            matrix[j][i] = number;
        }
    }
    for(int j = 0; j != row_numb ; j++){
        for(int i = 0; i != col_numb; i++){
            cout << matrix[j][i] << "\t"; 
        }
        cout << "\n";
    }

}

int main(){
    int matrix_1[MAX_COLUMNS][MAX_ROWS];
//    int matrix_2[MAX_COLUMNS][MAX_ROWS];
        
    matrix_fill(matrix_1);
//    matrix_fill(matrix_2);

return 0;
}
