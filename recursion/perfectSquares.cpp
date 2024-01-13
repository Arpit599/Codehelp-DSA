#include<iostream>
using namespace std;

int nearestSquare(int num){
    int low = 0;
    int high = num;
    int ans = 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mid * mid > num) high = mid - 1;
        else{
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}
int solve(int num, int sqrt, int it){
    if(num == 0 or num == 1) return num + it;
    if(num < 0) return INT_MAX;
    
    int minVal = INT_MAX;
    for(int i = 1; i <= sqrt; i++){
        int ways = solve(num - i * i, sqrt, it + 1);
        minVal = min(minVal, ways);
        if(minVal == INT_MAX) break;
    }
    return minVal;
}
int numSquares(int n) {
    int sqrt = nearestSquare(n);
    return solve(n, sqrt, 0);
}

int main(){
    cout << numSquares(12) << endl;
    return 0;
}