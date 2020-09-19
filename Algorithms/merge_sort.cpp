#include <iostream>

void merge_sort(double* array, int16_t array_size){
    if(array_size <= 1) return;
    int16_t middle = array_size/2;
    double* left = array; 
    double* right = array + middle;
    //BEWARE! Using address arithmetics: point + number gives
    //shifted arrray begin.
    int16_t* left_size = middle;     
    int16_t* right_size = array + middle;
    merge_sort(left, left_size);
    merge_sort(right, right_size);
    
    //Merge these two already sorted parts of array:
    double* buffer = new double[array_size];
    int16_t left_i = 0;
    int16_t right_i = 0;
    int16_t buffer_i = 0;
    while(left_i < left_size and right_i < right_size)
    {
        if(left[left_i] <= right[right_i]){
            //taking the lesser from the left part of array
            buffer[buffer_i] = left[left_i];
            left_i++;    
            buffer_i++;
        }else{
            //taking the lesser from the right  paret of array
            buffer[buffer_i] = right[right_i];
            right_i++;
            buffer_i++;
       }
    }    
    //coping left elements from the left side of array 
    while(left_i < left_size) {
        buffer[buffer_i] = left[left_i];
        left_i++;
        buffer_i++;
    }
    //coping left elements from the right side of array
    while(right_i < right_size) {
        buffer[buffer_i] = right[right_i];
        right_i++;
        buffer_i++;
    }
    //coping from buffer to the original array
    for(int16_t i = 0; i < array_size; i++){    
        array[i] = buffer[i];
    }
    delete[] buffer;
    
}

int main(){
    int A[] = {5, 4, 7, 1, 6, 8, 9, 3};
    int16_t N = A[]/A[0];
    merge_sort(A, N)

    return 0;
}
