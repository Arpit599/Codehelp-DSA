#include <iostream>
#include <stack>

using namespace std;

// 🔴 By reference pass krna bhul gya tha, yaha maine glti ki thi
void solve(stack<int> &s, int pos, int &ans){
    if(pos == 1){
        ans = s.top();
        cout << "Deleting "<< s.top() << endl;
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s, pos - 1, ans);
    s.push(temp);
}

int getMiddleElement(stack<int> &s){
    if(s.empty()){
        cout << "Stack is empty!" << endl;
        return -1;
    }
    int size = s.size();
    int pos = 0;

    if(size & 1) pos = (size >> 1) + 1;
    else pos = size >> 1;
    int ans = -1;
    solve(s, pos, ans);
    return ans;
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // s.push(6);

    int mid = getMiddleElement(s);
    cout << "Size before: " << s.size() << endl;
    cout << "Middle element: "<< mid << endl;
    cout << "Size after: " << s.size() << endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}