#include<iostream>
using namespace std;

bool checkPalindrome(string &s, int i){
    int n = s.length();
    if (i == (n/2)) return true;
    if(s[i] != s[n - i - 1]) return false;
    return checkPalindrome(s, i + 1);
}

int main(){
    string str1 = "hello!";
    string str2 = "nittin";
    cout << checkPalindrome(str1, 0) << " " << checkPalindrome(str2, 0) << endl;
    return 0;
}