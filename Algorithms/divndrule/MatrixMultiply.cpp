#include <iostream>
#include <vector>
#include "Timer.cpp"

using std::vector;

vector<vector<int>> sqMatrixMultiply(vector<vector<int>> A, vector<vector<int>> B){
    vector<vector<int>> C(4, vector<int>(4));
    for(int i = 0; i != 4; i++){
        for(int j = 0; j != 4; j++){
            C[i][j] = 0;
            for (int k = 0; k != 4; k++)
                C[i][j] = C[i][j] + A[i][k] * B[k][j]; 
        }
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

