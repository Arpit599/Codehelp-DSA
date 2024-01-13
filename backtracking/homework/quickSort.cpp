#include <iostream>
#include<vector>
using namespace std;


int getPartitionIdx(vector<int> &arr, int start, int end){
    int pivot = end;
    int i = start - 1, j = start;

    while(j < end){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[j], arr[i]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    return i;
}

void quickSort(vector<int> &arr, int start, int end){
    if(start < end){
        int partition = getPartitionIdx(arr, start, end);
        quickSort(arr, start, partition - 1);
        quickSort(arr, partition + 1, end);
    }
}


int main(){
    vector<int> arr = {4, 2, 1, 5, 8, 6, 7};
    quickSort(arr, 0, arr.size() - 1);
    for(auto i : arr) cout << i <<  " ";
    cout << endl;
    return 0;
}