#include <iostream>

void rotate( int a[], unsigned size, int shift){
    if ((shift % size == 0) or (shift == 0)) return;   
    for (int i = 0; i < (shift % size); i++){
        int tmp = a[0];
        for (int j = 0; j < size; j++){
            a[j] = a[j+1]; 
        }
        a[size - 1] = tmp;
    }
} 

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    rotate(A, 6, 8);
    
    for(int i = 0; i < 6; i++){
        std::cout << A[i] << " ";
    }
    return 0;
}
