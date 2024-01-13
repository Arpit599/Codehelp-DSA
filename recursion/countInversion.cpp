// NOTE 🔴: IMPORTANT Question!!!

#include<iostream>
using namespace std;

int countSwaps(int *arr, int low, int high){
    int mid = (low + high) / 2;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1];
    int right[n2] ;

    int temp = 0;
    for(int i = low; i <= mid; i++) left[temp++] = arr[i];
    temp = 0;
    for(int i = mid + 1; i <= high; i++) right[temp++] = arr[i];

    int l1 = 0, h1 = 0, k1 = low;
    int swaps = 0;

    while(l1 < n1 && h1 < n2){
        if(left[l1] > right[h1]){
            arr[k1++] = right[h1++];
            swaps += n1 - l1;
        }
        else if (left[l1] <= right[h1]) arr[k1++] = left[l1++];
    }

    while(l1 < n1) arr[k1++] = left[l1++];
    while(h1 < n2) arr[k1++] = right[h1++];

    return swaps;
}


int solve(int *arr, int low, int high){
    int count = 0;
    if (low < high){
        int mid = (low + high) / 2;
        count += solve(arr, low, mid);
        count += solve(arr, mid + 1, high);
        count += countSwaps(arr, low, high);
    }
    return count;
}


int main(){
    int arr[] = {2,5,1,3,4};
    
    int ans = solve(arr, 0, 4);
    cout << ans << endl;
    cout << endl;
    for(auto i: arr) cout << i << " ";
    return 0;
}