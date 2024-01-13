#include<iostream>
using namespace std;

int minimizeCost(vector<int>&days, vector<int>&costs, int currIdx, int validTill, int minCost){
    // Base case
    if(currIdx >= days.size()) return minCost;

    // Ek case solve kro baaki recursion dekhlega
    // Pehla case aaj ka ye hai, mujhe ticket leni bhi hai ya ni
    // Agar leni hai toh teeno type ki ticket aaj le kr try kro, baaki recursion dekh lega
    if(days[currIdx] <= validTill) return minimizeCost(days, costs, currIdx + 1, validTill, minCost);
    int mini1 = INT_MAX, mini2 = INT_MAX, mini3 = INT_MAX;
    for(int i = 0; i < 3; i++){
        if(i == 0) mini1 = minimizeCost(days, costs, currIdx + 1, days[currIdx], minCost + costs[0]);
        else if(i == 1) mini2 = minimizeCost(days, costs, currIdx + 1, days[currIdx] + 6, minCost + costs[1]);
        else mini3 = minimizeCost(days, costs, currIdx + 1, days[currIdx] + 29, minCost + costs[2]);
    }
    return min(mini1, min(mini2, mini3));
}


int main(){
    vector<int> days, costs;
    days.push_back(1);
    days.push_back(4);
    days.push_back(6);
    days.push_back(7);
    days.push_back(8);
    days.push_back(20);
    costs.push_back(2);
    costs.push_back(7);
    costs.push_back(15);
    cout <<"Min costs for the trip: " << minimizeCost(days, costs, 0, 0, 0)<< endl;
    return 0;
}