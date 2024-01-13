#include<iostream>
using namespace std;

void merge(vector<int> &nums, vector<int> &temp, int start, int end){
    int mid = start + (end - start) / 2;

    int i = start, j = mid + 1;
    int k = start;
    while(i <= mid && j <= end){
        if(nums[i] > nums[j]) temp[k++] = nums[j++];
        else temp[k++] = nums[i++];
    }

    while(i <= mid) temp[k++] = nums[i++];
    while(j <= end) temp[k++] = nums[j++];

    while(start <= end) {
        nums[start] = temp[start];
        start++;
    }
}

void mergeSort(vector<int> &nums, vector<int> &temp, int start, int end){
    if(start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSort(nums, temp, start, mid);
    mergeSort(nums, temp, mid + 1, end);
    merge(nums, temp, start, end);
}

void mergeInPlace(vector<int> &nums, int start, int end){
    int size = end - start + 1;
    int gap = size/2 + size % 2;
    while(gap > 0){
        int i = start;
        int j = i + gap;

        while(j <= end){
            if(nums[i] > nums[j]) swap(nums[i], nums[j]);
            i++;
            j++;
        }
        gap = gap <= 1 ? 0: gap/2 + gap%2;
    }
}

void mergeSortInplace(vector<int> &nums, int start, int end){
    if(start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSortInplace(nums, start, mid);
    mergeSortInplace(nums, mid + 1, end);
    mergeInPlace(nums, start, end);
}

vector<int> sortArray(vector<int>& nums) {
    mergeSortInplace(nums, 0, nums.size() - 1);
    return nums;
}

int main(){
    // int arr[] = {2,5,7,1,3,4};
    int arr[] = {7,6,5,4,3,2,1};
    mergeSort(arr, 0, 6);
    for(auto i : arr) cout << i << " ";
    cout << endl;
    return 0;
} 