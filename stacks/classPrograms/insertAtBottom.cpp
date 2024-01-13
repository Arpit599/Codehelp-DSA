#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s, ele);
    s.push(temp);
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    solve(s, 69);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}