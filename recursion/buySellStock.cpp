#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> &prices, int buyDay, int currDay, int &maxProfit){
    if(currDay >= prices.size()) return;

    if(prices[currDay] < prices[buyDay]) return solve(prices, currDay, currDay + 1, maxProfit);
    else if(prices[currDay] - prices[buyDay] > maxProfit) maxProfit = prices[currDay] - prices[buyDay];
    
    return solve(prices, buyDay, currDay + 1, maxProfit);
}

int maxProfit(vector<int>& prices) {
    int buyDay = 0;
    int maxProfit = 0;
    solve(prices, buyDay, 1, maxProfit);
    return maxProfit;
}

int main(){
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    int ans = maxProfit(prices);
    cout <<"Max profit: "<< ans << endl;
    return 0;
}

//🔴 NOTE: We are not using two loops approach because it can be done with one traversal, 
//approach being that if today's price is lower than last buy price then update buyDay because if there would 
//have been any profit it must have been stored in maxProfit variable and now we need to calculate maxProfit from this day