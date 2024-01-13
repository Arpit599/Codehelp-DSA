#include <vector>
#include <iostream>

using namespace std;

int solve(vector<int> weight,vector<int> profit, int n, int maxWeight, int idx, int profitSoFar, int weightSoFar){
	if(idx >= n) return profitSoFar;
	if(weightSoFar >= maxWeight) return profitSoFar;

	int a1 = 0;

    // 🔴 Yaha pr maine glti ki thi, iss condition ko bhul gya tha aur answer glt aaya tha
	if(weight[idx] <= maxWeight - weightSoFar) 
    a1 = solve(weight, profit, n, maxWeight, idx + 1, profitSoFar + profit[idx], weightSoFar + weight[idx]);

	int a2 = solve(weight, profit, n, maxWeight, idx + 1, profitSoFar, weightSoFar);
	return max(a1, a2);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight, value, n, maxWeight, 0, 0, 0);
}

int main(){
    vector<int> weights = {6, 5, 1, 5, 6, 5, 9};
    vector<int> profits = {5, 3, 4, 9, 6, 1, 1};
    int n = 7, maxWeight = 63;
    cout << knapsack(weights, profits, n, maxWeight) << endl;
    return 0;
}