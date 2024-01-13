#include<iostream>
#include<vector>
using namespace std;

// Ye solution glt hai, isme sirf 2 swapping elements mein comparison ho rha, but aisa ho skta hai ki 
// koi do elements aps mein cond meet na krre ho but unke swaps se further ans banega hi banega
//🔴 Isme maine glti ki thi
void solve(vector<int> &nums, int &ans, int idx){
    if(idx >= nums.size()){
        for(auto i : nums) cout << i << " ";
        cout << endl;
        ans += 1;
        return;
    }

    for(int i = idx; i < nums.size(); i++){
        if((nums[idx] % (i + 1) == 0 || (i + 1) % nums[idx] == 0) && (nums[i] % (idx + 1) == 0 || (idx + 1) % nums[i] == 0)){
            swap(nums[idx], nums[i]);
            solve(nums, ans, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
    return;
}

// Ye solution better hai, isme mai sirf ek number ko alg alg index pr rkh rha hu, baaki recursion dekh lega agr answer banta hai toh

void solve(vector<int> &visited, int n, int &ans, int num){
    if(num > n) {
        // for(int i = 1; i <= n; i++) cout << visited[i] << " ";
        // cout << endl;
        ans += 1;
        return;
    }
    for(int i = 1; i <= n; i++){
        if (visited[i] == 0 && (i % num == 0 || num % i == 0)){
            visited[i] = num;
            solve(visited, n, ans, num + 1);
            visited[i] = 0;
        }
    }
    return;
}

int countArrangement(int n) {
    vector<int> visited(n + 1, 0);
    int ans = 0;
    // vector<int> nums;
    // for(int i = 1; i <= n; i++) nums.push_back(i);
    // solve(nums, ans, 0);
    solve(visited, n, ans, 1);
    return ans;
}

int main(){
    cout << countArrangement(5) << endl;
    return 0;
}