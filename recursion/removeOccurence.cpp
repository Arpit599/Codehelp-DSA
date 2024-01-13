#include<iostream>
using namespace std;

string removeOccurrences(string s, string part) {
        int idx = s.find(part);
        int n = s.length();
        if (idx != string::npos){
            s = s.substr(0, idx) + s.substr(idx + part.length());
            return removeOccurrences(s, part);
        }
        else return s;  
    }

int main(){
    string s = "kpygkivtlqoockpygkivtlqoocssnextkqzjpycbylkaondsskpygkpygkivtlqoocssnextkqzjpkpygkivtlqoocssnextkqzjpycbylkaondsycbylkaondskivtlqoocssnextkqzjpycbylkaondssnextkqzjpycbylkaondshijzgaovndkjiiuwjtcpdpbkrfsi";
    string part = "kpygkivtlqoocssnextkqzjpycbylkaonds";

    s = removeOccurrences(s, part);
    cout << s << endl;
    return 0;
}