int solveUsingRecursion(vector<int>& values, vector<int> &weights, int n, int w, int idx){
	if(idx >= n) return 0;

	int include = 0;
	if(w - weights[idx] >= 0) include = values[idx] + solveUsingRecursion(values, weights, n, w - weights[idx], idx + 1);
	int exclude = 0 + solveUsingRecursion(values, weights, n, w, idx + 1);
	int ans = max(include, exclude);
	return ans;
}

int solveUsingMem(vector<int>& values, vector<int> &weights, int n, int w, int idx, vector<vector<int>>& dp){
	if(idx >= n) return 0;

	if(dp[w][idx] != -1) return dp[w][idx];

	// Yaha glti ki thi maine include direct calculate kiya tha 
	// jo ki glt hai kyuki agr recusion ka answer 0 bhi aata hai tab 
	// bhi include ki value values[idx] ho jaegi
	int include = 0;
	if(w - weights[idx] >= 0) include = values[idx] + solveUsingMem(values, weights, n, w - weights[idx], idx + 1, dp);
	int exclude = 0 + solveUsingMem(values, weights, n, w, idx + 1, dp);
	dp[w][idx] = max(include, exclude);
	return dp[w][idx];
}

// Bht gltiya ki thi 2D array mein, base ans banane mein bhi dikkt hui thi
int solveUsingTabulation(vector<int>& values, vector<int>& weights, int n, int capacity){
	vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
	for(int i = 0; i <= capacity; i++) dp[i][n] = 0;

	for(int i = 0; i <= capacity; i++){
		for(int j = n - 1; j >= 0; j--){
			int include = 0;
			if(i - weights[j] >= 0) include = values[j] + dp[i - weights[j]][j + 1];
			int exclude = 0 + dp[i][j + 1];
			dp[i][j] = max(include, exclude);
		}
	}
	return dp[capacity][0];
}

int solveUsingSO(vector<int>& values, vector<int>& weights, int n, int capacity){
	vector<int> curr(capacity + 1, -1);
	vector<int> next(capacity + 1, 0);

	for(int j = n - 1; j >= 0; j--){
		for(int i = 0; i <= capacity; i++){
			int include = 0;
			if(i - weights[j] >= 0) include = values[j] + next[i - weights[j]];
			int exclude = 0 + next[i];
			curr[i] = max(include, exclude);
		}
		// Bhul gya tha shift krna
		next = curr;
	}
	return curr[capacity];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	// int ans = solveUsingRecursion(values, weights, n, w, 0);

	// vector<vector<int>> dp(w + 1, vector<int>(n, -1));
	// int ans = solveUsingMem(values, weights, n, w, 0, dp);

	// int ans = solveUsingTabulation(values, weights, n, w);
	
	int ans = solveUsingSO(values, weights, n, w);
	return ans;
}