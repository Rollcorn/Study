#include <iostream>
#include "PriorityQueue.cpp"

using namespace std;

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int B[] = { 4, 49, 6, 15, 49, 22, 31, 108, 56, 34, 11, 18};
    PriorityQueue queue(A, 10);
    queue.printHeap();

    PriorityQueue queue2(B, 12);
    queue2.printHeap();
    
    queue.MaxHeapInsert(15);

    queue.printHeap();
    
    queue.HeapIncreaseKey(4, 46);

    queue.printHeap();

    queue.HeapExtractMax();

    queue.printHeap();

    return 0;
}
