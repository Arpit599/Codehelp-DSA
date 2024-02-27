class Solution {
public:
    int solveUsingRecursion(int n){
        if(n == 0 || n == 1) return n;
        return solveUsingRecursion(n - 1) + solveUsingRecursion(n - 2);
    }

    int solveUsingMemoization(int n, vector<int>&dp){
        if(n == 0 || n == 1) return n;
        
        // Check kro agr already dp vector mein  hai toh dobara kyu calculate krna
        if(dp[n] != -1) return dp[n];

        dp[n] = solveUsingMemoization(n - 1, dp) + solveUsingMemoization(n - 2, dp);
        return dp[n];
    }

    int solveUsingTabulation(int n){
        // Yaha glti ki thi, ye condition bhool gya tha
        if(n == 0 || n == 1) return n;

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }

    int solveUsingSO(int n){
        // Yaha glti ki thi, ye condition bhool gya tha
        if(n == 0 || n == 1) return n;

        int prev = 0;
        int curr = 1;

        for(int i = 2; i <= n; i++) {
            int temp = curr;
            curr = curr + prev;
            prev = temp;
        }

        return curr;
    }

    int fib(int n) {
        // int ans = solveUsingRecursion(n);

        // vector<int> dp(n+1, -1);
        // int ans = solveUsingMemoization(n, dp);

        // int ans = solveUsingTabulation(n);

        int ans = solveUsingSO(n);
        return ans;
    }
};