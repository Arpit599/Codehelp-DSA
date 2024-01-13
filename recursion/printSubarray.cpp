#include <iostream>

using namespace std;

void subarray(string &s, string curr, int currIdx, int size, vector<string> &ans){
    if(currIdx >= size){
        ans.push_back(curr);
        return;
    }
    subarray(s, curr, currIdx + 1, size, ans);
    subarray(s, curr + s[currIdx], currIdx + 1, size, ans);
}

int main(){
    string str = "abc";
    vector<string> ans;
    subarray(str, "", 0, str.length(), ans);
    for(auto i : ans) cout << i << endl;
    return 0;
}