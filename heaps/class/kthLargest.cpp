#include<iostream>
#include<queue>

using namespace std;

// kth largest nikaalne ke liye first k large elements store krke min heap mein, top element return krne pr kth largest in an array mil jaega
int getKthLargest(int *arr, int k, int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    // Process first k elements
    for(int i = 0; i < k; i++) pq.push(arr[i]);
    // Process rest of the elements
    for(int i = k; i < n; i++){
        if(pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}


int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int ans = getKthLargest(arr, 3, 6);
    cout << "Kth largest element: " << ans << endl;
    return 0;
}