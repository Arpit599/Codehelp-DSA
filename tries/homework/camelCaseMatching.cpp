class TrieNode{
public:
    char val;
    TrieNode* children[58];
    bool isTerminal;

    TrieNode(char val){
        this -> val = val;
        this -> isTerminal = false;
        for(int i = 0; i < 58; i++) this -> children[i] = NULL;
    }
};

void insert(TrieNode* root, string word){
    if(word.size() == 0){
        root -> isTerminal = true;
        return;
    }
    char ch = word[0];
    int idx = ch - 'A';
    if(root -> children[idx] == NULL) {
        TrieNode* child = new TrieNode(ch);
        root -> children[idx] = child;
    }
    insert(root -> children[idx], word.substr(1));
}

bool searchTrie(TrieNode* root, string word, int i){
    if(i >= word.size()){
        return root -> isTerminal;
    };
    
    char ch = word[i];
    int idx = ch - 'A';
    if(root -> children[idx] != NULL){
        return searchTrie(root -> children[idx], word, ++i);
    }
    else if(ch >='a' && ch <= 'z'){
        return searchTrie(root, word, ++i);
    }
    return false;
}


class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        TrieNode* root = new TrieNode('*');
        insert(root, pattern);
        for(auto q : queries) ans.push_back(searchTrie(root, q, 0));
        return ans;
    }
};