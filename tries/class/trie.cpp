#include<iostream>
#include<vector>
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
    if(root -> children[ch - 'a'] != NULL){
        insertWord(root -> children[ch  - 'a'], inp.substr(1));
    }
    else{
        TrieNode* child = new TrieNode(ch);
        root -> children[ch - 'a'] = child;
        insertWord(child, inp.substr(1));
    }
}

bool deleteWord(TrieNode* root, string s){
    if(s.size() == 0){
        if(root -> isTerminal){
            root -> isTerminal = false;
            return true;
        }
        return false;
    }
    char ch = s[0];
    if(root -> children[ch - 'a'] != NULL) return deleteWord(root -> children[ch - 'a'], s.substr(1));
    return false;
}

bool searchWord(TrieNode* root, string s){
    if(s.size() == 0) return root -> isTerminal;

    char ch = s[0];
    if(root -> children[ch - 'a'] != NULL) return searchWord(root -> children[ch - 'a'], s.substr(1));
    return false;
}

TrieNode* getPrefixLastNode(TrieNode* root, string prefix){
    if(prefix.size() == 0) return root;
    char ch = prefix[0];
    if(root -> children[ch - 'a'] != NULL) return getPrefixLastNode(root -> children[ch - 'a'], prefix.substr(1));
    return NULL;
}

void getWordsWithPrefix(TrieNode* root, string prefix, string curr, vector<string> &ans){
    if(root -> isTerminal) ans.push_back(prefix + curr);
    for(int i = 0; i < 26; i++){
        if(root -> children[i] != NULL){
            curr.push_back('a' + i);
            getWordsWithPrefix(root -> children[i], prefix, curr, ans);
            curr.pop_back();
        }
    }
}

void searchWordsByPrefix(TrieNode* root, string prefix, vector<string> &ans){
    TrieNode* prefixLastNode = getPrefixLastNode(root, prefix);
    if(prefixLastNode == NULL || prefixLastNode == root) return;
    getWordsWithPrefix(prefixLastNode, prefix, "", ans);
}

void getSuggestions(TrieNode* root, string input, vector<vector<string>> &ans){
    int idx = 0;

    TrieNode* curr = root;
    string prefix = "";
    while(idx < input.size()){
        if(curr -> children[input[idx] - 'a'] != NULL){
            prefix = prefix + input[idx];
            vector<string> prefixAns;
            getWordsWithPrefix(curr -> children[input[idx] - 'a'], prefix, "", prefixAns);
            ans.push_back(prefixAns);
            curr = curr -> children[input[idx] - 'a'];
        }
        else break;
        idx++;
    }
}

int main(){
    TrieNode* root = new TrieNode('*');
    int choice;
    
    bool takeInput = true;
    while(takeInput){
        cout << endl << "1. Insertion, 2. Deletion, 3. Word Search, 4. Search by prefix, 5. Suggestions, 6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch(choice){
            case 1:
            {
                string inp;
                cout <<"Enter string: ";
                cin >> inp;
                cout << endl;
                insertWord(root, inp);
                break;
            }
            case 2:
            {
                string inp;
                cout <<"Enter string: ";
                cin >> inp;
                cout << "Word deleted: " << deleteWord(root, inp) << endl;
                break;
            }
            case 3:
            {
                string inp;
                cout <<"Enter string: ";
                cin >> inp;
                cout << "Word present: " << searchWord(root, inp) << endl;
                break;
            }
            case 4:
            {   
                string prefix;
                vector <string> ans;
                cout <<"Enter prefix: ";
                cin >> prefix;
                searchWordsByPrefix(root, prefix, ans);
                if(ans.size() == 0){
                    cout << "Prefix not present" << endl;
                }
                else{
                    cout << "Words present: " << endl;
                    for(auto str : ans) cout << str <<  ", ";
                }
                cout << endl;
                break;
            }
            case 5:
            {
                string input;
                vector<vector<string>> ans;
                cout <<"Enter string: ";
                cin >> input;
                getSuggestions(root, input, ans);
                if(ans.size() == 0){
                    cout << "String not present" << endl;
                }
                else{
                    cout << "Words present: ";
                    for(int i = 0; i < ans.size(); i++){
                        cout << input.substr(0, i + 1) << " -> ";
                        for(auto str : ans[i]) cout << str <<  ", ";
                        cout << endl;
                    }
                }
                cout << endl;
                break;
            }
            case 6:
                takeInput = false;
                break;
            default:
                takeInput = false;
                break;
        }
        
    }
    return 0;
}