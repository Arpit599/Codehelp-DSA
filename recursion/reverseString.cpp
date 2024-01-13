#include <iostream>
using namespace std;

void reverse(string &s, int left, int right){
    if (left >= right) return;
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    reverse(s, left + 1, right - 1);
}

int main(){
    string str = "hello!";
    reverse(str, 0, str.length() - 1);
    cout << str << endl;
    return 0;
}