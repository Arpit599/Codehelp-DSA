#include <iostream>

using namespace std;

int findLastIndex(string &s, char target, int idx){
    if(idx < 0) return -1;
    if(s[idx] == target) return idx;
    return findLastIndex(s, target, idx - 1);
}


int main(){
    string str = "hello";
    cout << "The last occurence idx is, "<< findLastIndex(str, 'l', 4) << endl;
    return 0;
}