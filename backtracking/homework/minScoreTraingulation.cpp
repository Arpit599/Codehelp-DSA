#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &v, int start, int end){
        if(start == end - 1) return 0;
        int ans = INT_MAX;
        for(int k = start + 1; k < end; k++){
            ans = min(ans, (v[start] * v[k] * v[end] + solve(v, start, k) + solve(v, k, end)));
        }
        return ans;
    }

int minScoreTriangulation(vector<int>& values) {
    int min = solve(values, 0, values.size() - 1);
    return min;
}


int main(){
    vector<int> values = {1,3,1,4,1,5};
    cout << minScoreTriangulation(values) << endl;
    return 0;
}