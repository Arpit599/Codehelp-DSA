#include<iostream>
using namespace std;

void merge(int *arr, int low, int high){
    int mid = (low + high) / 2;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1];
    int right[n2] ;

    int temp = 0;
    for(int i = low; i <= mid; i++) left[temp++] = arr[i];
    temp = 0;
    for(int i = mid + 1; i <= high; i++) right[temp++] = arr[i];

    int l = 0, h = 0, k = low;

    while(l < n1 && h < n2){
        if(left[l] > right[h]) arr[k++] = right[h++];
        else if (left[l] <= right[h]) arr[k++] = left[l++];
    }

    while(l < n1) arr[k++] = left[l++];
    while(h < n2) arr[k++] = right[h++];
}


void mergeSort(int *arr, int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high);
    }
}


int main(){
    // int arr[] = {2,5,7,1,3,4};
    int arr[] = {7,6,5,4,3,2,1};
    mergeSort(arr, 0, 6);
    for(auto i : arr) cout << i << " ";
    cout << endl;
    return 0;
}