#include<iostream>
#include<vector>

using namespace std;

string solve(int num, vector< pair<int, string> > &map){
    if (num == 0) return "Zero";
    
    for(auto it: map){
        if (num >= it.first){
            string a = "";
            if(num >= 100) a = solve(num / it.first, map) + " ";
            string b = it.second;
            string c = "";
            if(num % it.first != 0) c = " " + solve(num % it.first, map);
            string ans = a + b + c;
            return ans;
        }
    }
    return "";
}

string numberToWords(int num) {
    vector< pair<int, string> > map = {
        {1000000000, "Billion"},
        {1000000, "Million"},
        {1000,  "Thousand"},
        {100, "Hundred"},
        {90, "Ninety"}, 
        {80, "Eighty"}, 
        {70, "Seventy"}, 
        {60, "Sixty"}, 
        {50, "Fifty"}, 
        {40, "Forty"}, 
        {30, "Thirty"}, 
        {20, "Twenty"},
        {19, "Nineteen"}, 
        {18, "Eighteen"}, 
        {17, "Seventeen"}, 
        {16, "Sixteen"}, 
        {15, "Fifteen"}, 
        {14, "Fourteen"}, 
        {13, "Thirteen"},
        {12, "Twelve"}, 
        {11, "Eleven"}, 
        {10, "Ten"}, 
        {9, "Nine"}, 
        {8, "Eight"}, 
        {7, "Seven"}, 
        {6, "Six"}, 
        {5, "Five"}, 
        {4, "Four"}, 
        {3, "Three"},
        {2, "Two"}, 
        {1, "One"}
    };
    string ans = solve(num, map);
    return ans;
}

int main(){
    string ans = numberToWords(2147483647);
    cout << ans << endl;
    return 0;
}