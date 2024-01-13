#include <iostream>
using namespace std;

bool binarySearch(int arr[], int size, int target, int low, int high){
    if(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return true;
        else if(arr[mid] < target){
            low = mid + 1;
            return binarySearch(arr, size, target, low, high);
        } else{
            high = mid - 1;
            return binarySearch(arr, size, target, low, high);
        }
    } else {
        return false;
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    bool ans = binarySearch(arr, 5, 2, 0, 4);
    cout << bool(ans) << endl;
    return 0;
}