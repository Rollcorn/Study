#include "assert.h"
#include <iostream>

class PriorityQueue
{
public:
    PriorityQueue(int *array, int array_length)
        : heap(new int[array_length]{0}), array_size(array_length)
    {
        heap_size = 0;
        for (auto i = 0; i != array_length; i++)
        {
            MaxHeapInsert(this->heap, array[i]);
        }
    };

    ~PriorityQueue(){
        delete[] heap;
    };
    
    void printHeap(){
        std::cout << '{';
        for (int i = 0; i != heap_size; i++)
            std::cout << heap[i] << ' ';
        std::cout << '}' << std::endl;
        std::cout << "Arr size " << array_size << " Heap size " << heap_size << std::endl;
    }

    //Вставляет элемент в множество S
    void MaxHeapInsert(int key)
    {
        heap_size++;    
        this->heap[heap_size-1] = -99999;
        HeapIncreaseKey(this->heap, heap_size - 1, key);
    }

    //Увеличивает значение ключа элемента х до значения k
    void HeapIncreaseKey(int i, int key)
    {
        assert(key > this->heap[i]);
        
            this->heap[i] = key;
            while ((i > 0) && (this->heap[Parent(i)] < this->heap[i]))
            {
                int tmp = this->heap[i];
                this->heap[i] = this->heap[Parent(i)];
                this->heap[Parent(i)] = tmp;
                i = Parent(i);
            }
    }

    int Left(int i)
    {
        return 2 * i + 1;
    }

    int Right(int i)
    {
        return 2 * i + 2;
    }

    int Parent(int i)
    {
        return (i - 1) / 2;
    }

    //возвращает элемент множества S с наибольшим ключом
    int HeapMax()
    {
        return heap[0];
    }

    //Удаляет и возвращает элемент множества S
    int HeapExtractMax()
    {
        assert(heap_size > 1);

        int heap_size = heap_size;
        int max = heap[1];
        heap[0] = heap[heap_size - 1];
        heap_size -= 1;
        MaxHeapify(0);
        return max;
    }

private:
    int array_size;
    int heap_size;
    int *heap;

    void MaxHeapify(int i)
    {
        int left = Left(i);
        int right = Right(i);
        int largest;

        if (left <= heap_size - 1 && heap[left] > heap[i])
        {
            largest = left;
        }
        else
            largest = i;

        if (right <= heap_size - 1 && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            int tmp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = tmp;
            MaxHeapify(largest);
        }
    }

    void MaxHeapInsert(int* array, int key)
    {
        heap_size++;    
        array[heap_size-1] = -99999;
        HeapIncreaseKey(array, heap_size - 1, key);
    }

    void HeapIncreaseKey(int* array, int i, int key)
    {
        assert(key > array[i]);
        
            array[i] = key;
            while ((i > 0) && (array[Parent(i)] < array[i]))
            {
                int tmp = array[i];
                array[i] = array[Parent(i)];
                array[Parent(i)] = tmp;
                i = Parent(i);
            }
    }

};
