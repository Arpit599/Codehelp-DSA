#include<iostream>
#include<vector>
#include<string>

using namespace std;


class TrieNode{
public:
    char val;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char val){
        this -> val = val;
        this -> isTerminal = false;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

void insertWord(TrieNode* root, string inp){
    if(inp.size() == 0){
        root -> isTerminal = true;
        return;
    }

    char ch = inp[0];
    int idx = ch - 'a';

    if(root -> children[idx] != NULL) insertWord(root -> children[idx], inp.substr(1));
    else{
        TrieNode* child = new TrieNode(ch);
        root -> children[idx] = child;
        insertWord(child, inp.substr(1));
    }
}

void findRoot(TrieNode* root, string inp, string &ans){
    if(inp.size() == 0) {
        ans = "";
        return;   
    }
    if(root -> isTerminal == true) {
        return;
    }

    char ch = inp[0];
    int idx = ch - 'a';

    if(root -> children[idx] != NULL) {
        ans = ans + ch;
        findRoot(root -> children[idx], inp.substr(1), ans);
    }
    else {
        ans = "";
    }
}

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string delimiter = " ";
        vector<string> words;

        // Vector of words banao space pr split krke
        while(sentence.find(delimiter) != string::npos){
            int idx = sentence.find(delimiter);
            string word = sentence.substr(0, idx);
            words.push_back(word);
            sentence = sentence.substr(idx + 1);
        }
        words.push_back(sentence);

        TrieNode* root = new TrieNode('*');

        // saare root words ko trie mein push kro
        for(auto s :  dictionary) insertWord(root, s);

        string ans = "";

        // Saare words ke root word check kro agr mile to ans mein include kro otherwise rehenedo
        for(auto s: words){
            string rootStr = "";
            findRoot(root, s, rootStr);
            if(rootStr.empty()) ans = ans + " " + s;
            else ans =  ans + " " + rootStr; 
        }

        // To remove starting ka space
        return ans.substr(1);
    }
};

int main(){
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    string ans = Solution().replaceWords(dictionary, sentence);
    cout << ans << endl;
    return 0;
}