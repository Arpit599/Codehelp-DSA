class Solution {
public:
    int solveUsingRecursion(string& text1, string& text2, int idx1, int idx2){
        if(idx1 >= text1.length()) return 0;
        if(idx2 >= text2.length()) return 0;

        int ans = 0;

        // Case: agar character match ho jaate hai toh dono index aage badhao
        if(text1[idx1] == text2[idx2]){
            ans = 1 + solveUsingRecursion(text1, text2, idx1 + 1, idx2 + 1);
        }
        else{
            // Case: agar character match ni hote hai toh 
            // ek baar idx1 aage bdhake dekho aur ek baar idx2 kyuki kisi se bhi answer ban skta hai
            ans = 0 + max(solveUsingRecursion(text1, text2, idx1 + 1, idx2), solveUsingRecursion(text1, text2, idx1, idx2 + 1));
        }
        return ans;
    }

    int solveUsingMem(string& text1, string& text2, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 >= text1.length()) return 0;
        if(idx2 >= text2.length()) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        int ans = 0;

        if(text1[idx1] == text2[idx2]){
            ans = 1 + solveUsingMem(text1, text2, idx1 + 1, idx2 + 1, dp);
        }
        else{
            ans = 0 + max(solveUsingMem(text1, text2, idx1 + 1, idx2, dp), solveUsingMem(text1, text2, idx1, idx2 + 1, dp));
        }
        dp[idx1][idx2] = ans;
        return dp[idx1][idx2];
    }

    int solveUsingTabulation(string& text1, string& text2){
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        for(int i = 0; i <= text1.length(); i++) dp[i][text2.length()] = 0;
        for(int i = 0; i <= text2.length(); i++) dp[text1.length()][i] = 0;
        
        for(int i = text1.length() - 1; i >= 0; i--){
            // Glti hui thi, ye loop ke bahar likh diya tha
            for(int j = text2.length() - 1; j >= 0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + dp[i + 1][j + 1];
                }
                else {
                    ans = 0 + max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingSO(string& text1, string& text2){
        vector<int> curr(text1.length() + 1, 0);
        vector<int> next(text1.length() + 1, 0);

        for(int j = text2.length() - 1; j >= 0; j--){
            // Glti hui thi, ye loop ke bahar likh diya tha
            for(int i = text1.length() - 1; i >= 0; i--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + next[i + 1];
                }
                else {
                    ans = 0 + max(curr[i + 1], next[i]);
                }
                curr[i] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int ans = solveUsingSO(s, rev);
        return ans;
    }
};