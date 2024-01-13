#include <iostream>
using namespace std;


void heapify(int* arr, int n, int idx){
    int lidx = 2 * idx;
    int ridx = 2 * idx + 1;
    int largestIdx = idx;

    if(lidx <= n && arr[largestIdx] < arr[lidx]) largestIdx = lidx;
    if(ridx <= n && arr[largestIdx] < arr[ridx]) largestIdx = ridx;
    if(largestIdx != idx){
        int temp = arr[idx];
        arr[idx] = arr[largestIdx];
        arr[largestIdx] = temp;
        heapify(arr, n, largestIdx);
    }
}

class Heap{
public:
    int* arr;
    int capacity;
    int size;

    Heap(int capacity){
        this -> arr = new int[capacity];
        this -> size = 0;
        this -> capacity = capacity;
    }

    void insert(int num){
        if(this -> size == this -> capacity){
            cout << "Heap overflow!, cant insert " << num << endl;
            return;
        }
        size++;
        arr[size] = num;
        int idx = size;

        while(idx > 1){
            int parentIdx = idx / 2;
            if(arr[parentIdx] < arr[idx]){
                int temp = arr[idx];
                arr[idx] = arr[parentIdx];
                arr[parentIdx] = temp;
                idx = parentIdx;
            }
            else{
                break;
            }
        }
    }

    int deleteFromHeap(){
        if(size == 0){
            cout << "Heap underflow!" << endl;
            return -1;
        }
        else{
            int answer = arr[1];
            arr[1] = arr[size];
            size--;
            heapify(arr, size, 1);
            // int idx = 1;
            // while(idx < size){
            //     int leftChild = idx * 2;
            //     int rightChild = 2 * idx + 1;
            //     int largestIdx = idx;
            //     if(leftChild <= size && arr[leftChild] > arr[largestIdx]){
            //         largestIdx = leftChild;
            //     }
            //     if(rightChild <= size && arr[rightChild] > arr[largestIdx]){
            //         largestIdx = rightChild;
            //     }
            //     if(largestIdx == idx) break;
            //     else{
            //         int temp = arr[idx];
            //         arr[idx] = arr[largestIdx];
            //         arr[largestIdx] = temp;
            //         idx = largestIdx;
            //     }
            // }
            return answer;
        }
    }

    void print(){
        cout << "Printing heap" << endl;
        for(int i = 1; i <= size; i++) cout << arr[i] << " ";
        cout << endl;
    }

};

void buildHeap(int *arr, int n){
    for(int i = n / 2; i > 0; i--) heapify(arr, n, i);
}

void heapSort(int *arr, int n){
    while(n != 1){
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main(){
    int arr[] = {-1,5,10,15,20,25,12};
    int n = 6;
    buildHeap(arr, n);
    heapSort(arr, n);
    for(int i = 1; i <= 6; i++) cout << arr[i] << " ";
    cout << endl;

    // Heap h = Heap(5);
    // h.insert(11);
    // h.insert(5);
    // h.insert(15);
    // h.insert(10);
    // h.insert(20);
    // h.print();
    // h.deleteFromHeap();
    // h.print();
    // h.deleteFromHeap();
    // h.print();
    // h.deleteFromHeap();
    // h.print();
    // h.deleteFromHeap();
    // h.print();
    // h.deleteFromHeap();
    // h.print();
    // h.deleteFromHeap();
    // h.print();
    return 0;
}