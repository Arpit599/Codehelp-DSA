#include<vector>
#include<string>

class customCompare{
public:
bool operator()(pair<int, string> &a, pair<int, string> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m1;
        priority_queue<pair<int, string>, vector<pair<int, string>>, customCompare > q;
        vector<string> unique;

        for(auto s : words){
            if(m1.find(s) == m1.end()) m1[s] = 1;
            else m1[s]++;
        }
        for(auto i = m1.begin(); i != m1.end(); i++) cout << i -> first << " " << i->second << endl;

        for(auto it = m1.begin(); it != m1.end(); it++) unique.push_back(it -> first);

        for(int i = 0; i < k; i++) {
            pair<int, string>p;
            p.first = m1[unique[i]];
            p.second = unique[i];
            q.push(p);
        }

        for(int i = k; i < unique.size(); i++){
            pair<int, string> top = q.top();
            if(top.first < m1[unique[i]] || (top.first == m1[unique[i]] && top.second > unique[i])){
                q.pop();
                pair<int, string>p;
                p.first = m1[unique[i]];
                p.second = unique[i];
                q.push(p);
            }
        }

        vector<string> res;
        
        while(!q.empty()){
            pair<int, string> top = q.top();
            res.push_back(top.second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};