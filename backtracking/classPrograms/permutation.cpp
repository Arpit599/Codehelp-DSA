#include <iostream>

using namespace std;

// This is pure recursion, we are making copies of string s in every recursive call
// O/P: abc acb bac bca cab cba
void printPermutationWithoutRef(string s, int idx){
    if(idx >= s.length()){
        cout << s << " ";
        return;
    }
    for(int j = idx; j < s.length(); j++){
        swap(s[idx], s[j]);
        printPermutationWithoutRef(s, idx + 1);
    }
}

// This is pure recursion, but now we are using reference of string s in every recursive call
// O/P: abc acb cab cba abc acb
void printPermutationWithRef(string &s, int idx){
    if(idx >= s.length()){
        cout << s << " ";
        return;
    }
    for(int j = idx; j < s.length(); j++){
        swap(s[idx], s[j]);
        printPermutationWithRef(s, idx + 1);
    }
}

// This is with backtracking, we are using reference of string s in every recursive call 
// and also nullifying swap operation to maintain original string
// O/P: abc acb bac bca cba cab
void printPermutationWithBacktracking(string &s, int idx){
    if(idx >= s.length()){
        cout << s << " ";
        return;
    }
    for(int j = idx; j < s.length(); j++){
        swap(s[idx], s[j]);
        printPermutationWithBacktracking(s, idx + 1);
        swap(s[j], s[idx]);
    }
}

int main(){
    string s1 = "abc", s2 = "abc", s3 = "abc";
    printPermutationWithoutRef(s1, 0);
    cout << endl;
    printPermutationWithRef(s2, 0);
    cout << endl;
    printPermutationWithBacktracking(s3, 0);
    cout << endl;
    return 0;
}