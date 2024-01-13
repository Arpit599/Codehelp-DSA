#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&nums, int &maxAmt, int currAmt, int idx){
        if(idx >= nums.size()) return;
        if(currAmt + nums[idx] > maxAmt) maxAmt = currAmt + nums[idx];
        solve(nums, maxAmt, currAmt, idx + 1);
        solve(nums, maxAmt, currAmt + nums[idx], idx + 2);
    }

int rob(vector<int>& nums) {
    int maxAmt = 0;
    solve(nums, maxAmt, 0, 0);
    return maxAmt;
}

int main(){
    vector<int> amount;
    amount.push_back(7);
    amount.push_back(2);
    amount.push_back(9);
    amount.push_back(10);
    amount.push_back(12);
    amount.push_back(14);
    int ans = rob(amount);
    cout <<"Max amount that can be stolen: "<< ans << endl;
    return 0;
}