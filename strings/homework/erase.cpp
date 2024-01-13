#include <iostream>

using namespace std;

void erase( string &s, int start = 0, int sizeToDelete = 0){
    if(sizeToDelete >= s.length() || start >= s.length()) return;
    if(start == 0 && sizeToDelete == 0) {
        s = "";
        return;
    };

    int k = start + 1;
    while(s[k] != '\0'){
        cout << k << " " << s[k] << " " << sizeToDelete << endl;
        s[k] = s[k + sizeToDelete];
        k++;
        // sizeToDelete--;
    }
    if(sizeToDelete == s.length() - 1) s[k] = '\0';
    // s[k] = '\0';
}

int main(){
    string s= "abcdef";
    erase(s, 0, 5);
    cout << "String => " << s << endl;
    for(auto i : s) cout << i << " ";
    return 0;
}