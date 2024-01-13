// 🔴 THIS IS ASKED IN INTERVIEW!!! IMPORTANT !!!!

// Lets look at how we can allocate,
// 1. Integer on heap, with & w/o new keyword
// 2. 1D array on heap, with & w/o new keyword
// 3. 2D array on heap, with & w/o new keyword

// new returns address to a pointer on heap

#include <iostream>
using namespace std;

void integerAllocation(){
    int *intWithNewKeyWord = new int(5);
    cout << "intWithNewKeyWord: " << *intWithNewKeyWord  << endl;
    delete intWithNewKeyWord;

    // void *voidPtr = malloc(4);
    // int *intPtr = (int*) voidPtr;
    int *intPtr = (int*) malloc(4);
    *intPtr = 10;
    cout << "intWithoutNewKeyWord: " << *intPtr << endl;
    free(intPtr);
}

void arrayAllocation(){
    int *arr = new int[5];
    for(int i = 0; i < 5; i++) arr[i] = i;
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    delete[] arr;
    // void *arrPtr = malloc(sizeof(int) * 5);
    // int *intArrPtr = (int*) arrPtr;
    int *intArrPtr = (int*) malloc(sizeof(int) * 5);
    for(int i = 0; i < 5; i++) intArrPtr[i] = i;
    for(int i = 0; i < 5; i++) cout << intArrPtr[i] << " ";
    cout << endl;
    free(intArrPtr);
}

void matrixAllocation(){
    int rows = 5, cols = 4;
    int **rowPtr = new int*[rows];
    for(int i = 0; i < rows; i++) rowPtr[i] = new int[cols];
    for(int i = 0; i < rows; i++) for(int j = 0; j < cols; j++) rowPtr[i][j] = i + j;
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) cout << rowPtr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < rows; i++) delete[] rowPtr[i];
    delete[] rowPtr;

    // void *ptr = malloc(sizeof(int*) * rows);
    // int **rowPtrMalloc = (int**) ptr;
    int **rowPtrMalloc = (int**) malloc(sizeof(int*) * rows);
    for(int i = 0; i < rows; i++) rowPtrMalloc[i] = (int*)malloc(sizeof(int) * cols);
    for(int i = 0; i < rows; i++) for(int j = 0; j < cols; j++) rowPtrMalloc[i][j] = i + j;
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) cout << rowPtrMalloc[i][j] << " ";
        cout << endl;
    }
    for(int i = 0; i < rows; i++) free(rowPtr[i]);
    free(rowPtr);
}

int main(){
    // integerAllocation();
    // arrayAllocation();
    matrixAllocation();
    return 0; 
}