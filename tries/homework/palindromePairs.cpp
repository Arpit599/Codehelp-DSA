class TrieNode{
public:
    char val;
    TrieNode* children[26];
    int idx;
    TrieNode(char val){
        this -> val = val;
        this -> idx = -1;
        for(int i = 0; i < 26; i++) this -> children[i] = NULL;
    }
};

class Trie{
    TrieNode* root;
    void insertUtil(TrieNode* root, string word, int idx){
        if(word.size() == 0){
            root -> idx = idx;
            return;
        }
        char ch = word[0];
        int i = word[0] - 'a';
        if(root -> children[i] != NULL){
            return insertUtil(root -> children[i], word.substr(1), idx);
        }
        else{
            TrieNode* child = new TrieNode(ch);
            root -> children[i] = child;
            return insertUtil(root -> children[i], word.substr(1), idx);
        }
    }

    bool isPalindrome(string &word, int low, int high){
        while(low <= high){
            if(word[low] != word[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    void searchByPrefixAndCheckPalindrome(TrieNode* root, vector<int> &pairs, string str){
        if(root -> idx != -1) {
            bool check = isPalindrome(str, 0, str.length() - 1);
            if(check) pairs.push_back(root -> idx);
        }
        for(int i = 0; i < 26; i++){
            if(root -> children[i] != NULL) {
                str.push_back('a' + i);
                searchByPrefixAndCheckPalindrome(root -> children[i], pairs, str);
                // Yaha glti hui thi, back-tracking ke liye important hai
                str.pop_back();
            }
        }
    }

    void getPalindromicPairsUtil(TrieNode* root, string &word, vector<int> &pairs){
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(root -> idx != -1) if(isPalindrome(word, i, word.length() - 1)) pairs.push_back(root -> idx);
            if(root -> children[idx] != NULL) root = root -> children[idx];
            else return;
        }
        searchByPrefixAndCheckPalindrome(root, pairs, "");
    }

public:
    Trie(){
        this -> root = new TrieNode('*');
    }

    void insert(string word, int idx){
        insertUtil(root, word, idx);
    }

    void getPalindromicPairs(string word, vector<int> &pairs){
        getPalindromicPairsUtil(root, word, pairs);
    }  
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        Trie t;
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            t.insert(s, i);
        }
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            vector<int> pairs;
            t.getPalindromicPairs(s, pairs);
            for(auto p : pairs){
                if(i != p) ans.push_back({i, p});
            }
        }
        return ans;
    }
};