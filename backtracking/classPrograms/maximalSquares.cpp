//🔴 IMPORTANT, revise...glt hua tha loop laga kr max side nikala tha for each element jabki recursion sambhaal lega

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<char>>& matrix, int currX, int currY, int rows, int cols, int &maxSide){
    if(currX >= rows || currY >= cols) return 0;

    int right = solve(matrix, currX, currY + 1, rows, cols, maxSide);
    int down = solve(matrix, currX + 1, currY, rows, cols, maxSide);
    int diagonal = solve(matrix, currX + 1, currY + 1, rows, cols, maxSide);

    int ans = min(right, min(diagonal, down));
    
    if(matrix[currX][currY] == '1'){
        ans += 1;
        maxSide = max(maxSide, ans);
    }
    else return 0;

    return ans;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int maxSide = 0;
    solve(matrix, 0, 0, matrix.size(), matrix[0].size(), maxSide);
    return maxSide != INT_MIN ? maxSide * maxSide: 0;
}

int main(){
    vector<vector<char> > matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};
    cout << maximalSquare(matrix) << endl;
    return 0;
}