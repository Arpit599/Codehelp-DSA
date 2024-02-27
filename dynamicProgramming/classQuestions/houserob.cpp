class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr){
        if(curr >= nums.size()) return 0;

        int include = nums[curr] + solveUsingRecursion(nums, curr + 2);
        int exclude = 0 + solveUsingRecursion(nums, curr + 1);

        int ans = max(include, exclude);
        return ans;
    }

    // Sirf ek variable change hora hai function calls mein isliye 1D dp lgegi
    int solveUsingMemoization(vector<int>& nums, int curr, vector<int>& dp){
        if(curr >= nums.size()) return 0;

        // Agr already present hai toh kyu aage calculate krna
        if(dp[curr] != -1) return dp[curr];

        int include = nums[curr] + solveUsingMemoization(nums, curr + 2, dp);
        int exclude = 0 + solveUsingMemoization(nums, curr + 1, dp);

        dp[curr] = max(include, exclude);
        return dp[curr];
    }

    int solveUsingTabulation(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, -1);
        // Mujhe 0 se start krne pr ni pta kitna max amt hoga but last house pr jo amount hai question mein utna hi profit hoga
        dp[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--){
            int include = nums[i];
            if(i + 2 < n) include += dp[i + 2];
            int exclude = 0 + dp[i + 1];
            dp[i] = max(include, exclude);
        }
        return dp[0];
    }

    int solveUsingSO(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        // As dp[i] is dependent on dp[i + 1] and dp[i + 2] we can use three variables for space optimization

        // next aur prev ko shuru mein kuch bhi rkhlo fark ni pdta kyuki ye first iteration ke baad shi update ho jaenge but curr ko last value pr rkhna pdega
        int next = 0;
        int prev = 0;
        int curr = nums[n - 1];

        for(int i = n - 2; i >= 0; i--){
            int include = nums[i];
            if(i + 2 < n) include += next;

            int exclude = 0 + curr;
            prev = max(include, exclude);

            // Shifting
            next = curr;
            curr = prev;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        // int ans = solveUsingRecursion(nums, 0);

        // int n = nums.size();
        // vector<int> dp(n, -1);
        // int ans = solveUsingMemoization(nums, 0, dp);

        // int ans = solveUsingTabulation(nums);

        int ans = solveUsingSO(nums);
        return ans;
    }
};