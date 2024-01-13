#include<iostream>
using namespace std;

bool solve(string &s, string &p, int n1, int n2){
    if(n1 == s.length() && n2 == p.length()) return true;
    if(n1 == s.length() && n2 < p.length()){
        while(n2 < p.length()){
            if(p[n2] != '*') return false;
            n2++;
        }
        return true;
    }

    if(p[n2] == '*') return solve(s, p, n1 + 1, n2) or solve(s, p, n1, n2 + 1);
    else if(p[n2] == '?' or p[n2] == s[n1]) return solve(s, p, n1 + 1, n2 + 1);
    else return false;
}

bool isMatch(string s, string p) {
    return solve(s, p, 0, 0);
}

int main(){
    cout << isMatch("abcabczzzde", "*abc???de*") << endl;
    return 0;
}