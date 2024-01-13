#include <vector>
#include <iostream>
using namespace std;

bool isSafe(vector < vector < int > > & arr, int n, vector < vector < int > > & visited, int srcx, int srcy);

void solve(vector < vector < int > > & arr, int n, vector < vector < int > > & visited, int currx, int curry, string path, vector<string> &ans){
    // Base case, when rat has reached the other end
    if(currx == n - 1 && curry == n - 1){
        ans.push_back(path);
        return;
    }

    // UP
    if(isSafe(arr, n, visited, currx - 1, curry)){
        visited[currx - 1][curry] = 1;
        solve(arr, n, visited, currx - 1, curry, path + 'U', ans);
        visited[currx - 1][curry] = 0; //Backtracking, marking this as un-visited so that this co-ordinate can be used in other paths from recursion
    }
    // DOWN
    if(isSafe(arr, n, visited, currx + 1, curry)){
        visited[currx + 1][curry] = 1;
        solve(arr, n, visited, currx + 1, curry, path + 'D', ans);
        visited[currx + 1][curry] = 0;
    }
    // LEFT
    if(isSafe(arr, n, visited, currx, curry - 1)){
        visited[currx + 1][curry] = 1;
        solve(arr, n, visited, currx, curry - 1, path + 'L', ans);
        visited[currx + 1][curry] = 0;
    }
    // RIGHT
    if(isSafe(arr, n, visited, currx, curry + 1)){
        visited[currx][curry + 1] = 1;
        solve(arr, n, visited, currx, curry + 1, path + 'R', ans);
        visited[currx][curry + 1] = 0;
    }
    return;
}

bool isSafe(vector < vector < int > > & arr, int n, vector < vector < int > > & visited, int srcx, int srcy){
    if(srcx >= n or srcx >= n or srcx < 0 or srcy < 0 or visited[srcx][srcy] == 1 or arr[srcx][srcy] == 0) return false;
    return true;
}


vector <string> searchMaze(vector < vector <int> > & arr, int n) {
    // Write your code here.
    vector<string> ans;
    if(arr[0][0] == 0){
        ans.push_back("");
        return ans;
    }
    
    vector<vector <int> > visited(n, vector<int>(n, 0));

    // 🔴 Yaha maine glti ki thi, iske bina glt answers include honge jisme wps aajaega 0, 0 pr
    visited[0][0] = 1;
    solve(arr, n, visited, 0, 0, "", ans);
    return ans;
}


int main(){
    vector<vector <int> > maze = {
        {1, 1},
        {1, 1}
    };
    vector<string> ans;
    ans = searchMaze(maze, 2);
    for(auto i: ans) cout << i << endl;
    return 0;
}