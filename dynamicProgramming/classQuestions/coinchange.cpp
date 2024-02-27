class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int target){
        if(target == 0) return 0;
        if(target < 0) return INT_MAX;

        int mini = INT_MAX;
        int ans = 0;

        // Ye hai explore all possible ways wala pattern, isme loop hi lagega
        for(int i = 0; i < coins.size(); i++){
            int recKaAns = solveUsingRecursion(coins, target - coins[i]);
            if(recKaAns != INT_MAX) {
                ans = 1 + recKaAns;
                mini = min(mini, ans);
            }
        }
        return mini;
    }

    int solveUsingMemoization(vector<int>& coins, int target, vector<int> &dp){
        if(target == 0) return 0;
        if(target < 0) return INT_MAX;

        if(dp[target] != -1) return dp[target];

        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0; i < coins.size(); i++){
            int recKaAns = solveUsingMemoization(coins, target - coins[i], dp);
            if(recKaAns != INT_MAX) {
                ans = 1 + recKaAns;
                mini = min(mini, ans);
            }
        }
        dp[target] = mini;
        return dp[target];
    }

    // Isse likhne mein dikkt hui thi, inner loop ki if condition mein fasa tha
    int solveUsingTabulation(vector<int>& coins, int target){
        if(target == 0) return 0;
        
        vector<int> dp(target + 1, -1);
        dp[0] = 0;

        for(int i = 1; i <= target; i++){
            int mini = INT_MAX;
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    int temp = 1 + dp[i - coins[j]];
                    mini = min(mini, temp);
                }
            }
            dp[i] = mini;
        }
        return dp[target];
    }

    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRecursion(coins, amount);
        // return ans == INT_MAX ? -1 : ans;

        // vector<int> dp(amount + 1, -1);
        // int ans = solveUsingMemoization(coins, amount, dp);
        // return ans == INT_MAX ? -1 : ans;

        int ans = solveUsingTabulation(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};