#include <iostream>
#include <type_traits>

int Parent(int i){
    return i/2 - 1;
}

int Left(int i){
    return 2*i + 1;
}

int Right(int i){
    return 2*i + 2;
}

void maxHeapify(int* Arr,int arrSize, int i){
    int l_node = Left(i);
    int r_node = Right(i);
    int largest;

    if (l_node < arrSize and Arr[l_node] > Arr[i])
        largest = l_node;
    else largest = i;
    
    if (r_node < arrSize and Arr[r_node] > Arr[largest])
        largest = r_node;

    if (largest != i){
        int tmp = Arr[i];
        Arr[i] = Arr[largest];
        Arr[largest] = tmp;
        maxHeapify(Arr, arrSize, largest);
    }
}

void buildMaxHeap(int* Arr, int arrSize){
    for (int i = arrSize/2 - 1; i >= 0; i--)
        maxHeapify(Arr, arrSize, i);
}

void Heapsort(int* arr, int arr_size){
    
    buildMaxHeap(arr,arr_size);
    
    int heap_size = arr_size;
    
    for (int i = arr_size - 1; i != 0; i--)
    {

        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        heap_size -= 1;        
        maxHeapify(arr, heap_size, 0);
    }
}

void printHeap(int* arr, int size){
    
    for (int i = 0; i != size; i++)
        std::cout << " " << arr[i];
    std::cout << '\n';
}

int main(){
    int array[]= {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(array)/sizeof(int);
    /*
    printHeap(array, size);
    buildMaxHeap(array, size);
    printHeap(array, size);
    */
    int array2[]= {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size2 = sizeof(array2)/sizeof(int);
    /*
    printHeap(array2, size2);
    buildMaxHeap(array2, size2);
    printHeap(array2, size2);
    */
    Heapsort(array, size);
    printHeap(array, size);

    Heapsort(array2, size2);
    printHeap(array2, size2);

    return 0;
}
