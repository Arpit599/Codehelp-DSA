#include<iostream>
#include<vector>
using namespace std;

void createMapping(string &s){
    vector<char> alphabets(26, '\0');

    char start = 'a';
    for(auto ch: s){
        if(alphabets[ch - 'a'] == '\0'){
            alphabets[ch - 'a'] = start;
            start++;
        }
    }
    for(int i = 0; i < s.length(); i++) s[i] = alphabets[s[i] - 'a'];
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    createMapping(pattern);
    for(auto word: words){
        string temp = word;
        createMapping(temp);
        if(temp == pattern) ans.push_back(word);
    }
    return ans;
}


int main(){
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> res = findAndReplacePattern(words, pattern);
    for(auto i : res) cout << i <<  " ";
    cout << endl;
    return 0;
}