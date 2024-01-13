#include<iostream>
using namespace std;

void solve(string num1, string num2, int p1, int p2, string &ans, int carry=0){
    // Base case
    if(p1 < 0 && p2 < 0){
        if(carry != 0){
            char ch = carry + '0';
            ans.push_back(ch);
            return;
        }
        return;
    }

    // Ek case recursion se solve
    int n1 = p1 >= 0 ? num1[p1] - '0' : 0;
    int n2 = p2 >= 0 ? num2[p2] - '0' : 0;
    int res = n1 + n2 + carry;
    int digit = res % 10;
    carry = res / 10;
    ans.push_back(digit + '0');

    //Baaki recursion dekhlega
    return solve(num1, num2, p1 - 1, p2 - 1, ans, carry);
}

string addStrings(string num1, string num2) {
    string ans = "";
    solve(num1, num2, num1.length() - 1, num2.length() - 1, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    cout<< addStrings("11", "123") << endl;
    return 0;
}