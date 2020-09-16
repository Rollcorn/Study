#include <iostream>
#include <vector>

void insert_sort(int A[], int N){
    int pos, j, key;
    for(pos = 1; pos < N; pos++){
        key = A[pos];
        j = pos - 1;
        while(j >= 0 and A[j] > key){
            A[j+1] = A[j];
            j -= 1;
        }
        A[j+1] = key;
    }
}

void printArray(int arr[], int n)  
{   
    for (int i = 0; i < n; i++)  
        std::cout << arr[i] << " ";  
    std::cout << std::endl; 
} 

int main(){
    int  A[] = {5, 2, 4, 6, 1, 3};
    int N = sizeof(A) / sizeof(A[0]);
    printArray(A, N);
    insert_sort(A, N);
    printArray(A, N);






return 0;
}
