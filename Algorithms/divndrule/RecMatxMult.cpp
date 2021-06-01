#include <iostream>
#include <vector>
#include "Timer.cpp"

using std::vector;

vector<vector<int>> recMatMul(vector<vector<int>> A, vector<vector<int>> B){
    int arrSize = A.size();
    vector<vector<int>> C(arrSize, vector<int>(arrSize));
    if (arrSize == 1)
        C[1][1] = A[1][1] * B[1][1];
    else{
        C[1][1] = recMatMul(A[1][1], B[1][1]) +recMatMul(A[1][2], B[2][1]);



        
    } 
    
    return C;

}



int main(){
   Timer t;
   vector<vector<int>> arr1 = {{1, 2, 3, 4}, 
                               {2, 3, 4, 5}, 
                               {3, 4, 5, 6}, 
                               {4, 5, 6, 7}};

   vector<vector<int>> arr2 = {{1, 2, 3, 4},
                               {2, 3, 4, 5}, 
                               {3, 4, 5, 6}, 
                               {4, 5, 6, 7}};

    vector<vector<int>> res = sqMatrixMultiply(arr1, arr2);
    for (int i = 0; i != 4; i++){
        for (int j = 0; j != 4; j++)
            std::cout << res[i][j] << ' ';
        std::cout << '\n';
    }
        
    return 0;
}

