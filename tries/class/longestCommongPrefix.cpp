
#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
public:
    char val;
    bool isTerminal;
    TrieNode* children[26];
    int childCount;

    TrieNode(char val){
        this -> val = val;
        this -> isTerminal = false;
        this -> childCount = 0;
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
    
    if(root -> children[ch - 'a'] != NULL){
        insertWord(root -> children[ch  - 'a'], inp.substr(1));
    }
    else{
        root -> childCount++;
        TrieNode* child = new TrieNode(ch);
        root -> children[ch - 'a'] = child;
        insertWord(child, inp.substr(1));
    }
}


void calculatePrefix(TrieNode* root, string &prefix, string in){
    if(root -> childCount > 1 || in.size() == 0 || root -> isTerminal) return;
    char ch = in[0];
    if(root -> children[ch - 'a'] != NULL){
        prefix += ch;
        calculatePrefix(root -> children[ch - 'a'], prefix, in.substr(1));
    }
}


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('*');
        // Saare words ko insert krdo pehle trie mein
        for(auto s: strs) insertWord(root, s);
        string prefix = "";
        // Fir check kro koi bhi ek string leke if kisi bhi string character ke against multiple childs hai ya koi character terminal hai then yhi tk longest prefix hoga
        calculatePrefix(root, prefix, strs[0]);
        return prefix;
    }
};