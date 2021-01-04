#include <iostream>
#include "Timer.cpp"

//The programm sums up the elem of two demension matrix (int) by columns 
//and by rows. Measure work time  
using namespace std;

int** matrix_generator(int dim_1, int dim_2){
    int** matrix = new int* [dim_1];
    for(int i =0; i < dim_1; i++)
        matrix[i] = new int [dim_2];
    return matrix;
}

void fill_matrix(int** matrix, int dim_1, int dim_2){    
    int number;
    for(int i = 0; i < dim_1; i++){
        for(int j = 0; j < dim_2; j++){
            cout << "Enter number: " << endl;
            cin >> number;
            matrix[i][j] = number;
        }
    }
}

void matrix_print(int** matrix, int dim_1, int dim_2){
    for(int j = 0; j < dim_1; j++){
        for(int i = 0; i < dim_2; i++){
            cout << matrix[j][i] << "\t"; 
        }
        cout << "\n";
    }
}

void matrix_destroyer(int** matrix, int dim_1){
    for(int i = 0; i < dim_1; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}

int** matrix_sum(int** matrix_1, int** matrix_2, int dim_1, int dim_2){
    int** sum = matrix_generator(dim_1, dim_2);
    for(int i = 0; i < dim_1; i++){
        for(int j = 0; j < dim_2; j++)
            sum[i][j] = matrix_1[i][j] + matrix_2[i][j];        
    }
    
    return sum;
}


int main(){
    Timer t;
    int** matrix_1;
    int** matrix_2;
    int DIM1, DIM2;
    cout << "Enter Dimension 1 and Dimension 2, sizes of matrix: " << endl;
    cin >> DIM1 >> DIM2;
       
    matrix_1 = matrix_generator(DIM1, DIM2);
    matrix_2 = matrix_generator(DIM1, DIM2);

    cout << "Enter numbers to Matrix 1:" << endl;
    fill_matrix(matrix_1, DIM1, DIM2);

    cout << "Enter numbers to Matrix 2:" << endl;
    fill_matrix(matrix_2, DIM1, DIM2);

    cout << "Matrix 1:" << endl;
    matrix_print(matrix_1, DIM1, DIM2);
    cout << "Matrix 2:" << endl;
    matrix_print(matrix_2, DIM1, DIM2);

    int** sum_of_matrix = matrix_sum(matrix_1, matrix_2, DIM1, DIM2); 
    cout << "The sum of matrix by columns is " << endl;
    matrix_print(sum_of_matrix, DIM1, DIM2);

      
    matrix_destroyer(matrix_1, DIM1);
    matrix_destroyer(matrix_2, DIM1);
    matrix_destroyer(sum_of_matrix, DIM1);
return 0;
}
