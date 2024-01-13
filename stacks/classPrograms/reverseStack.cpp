#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s, ele);
    s.push(temp);
}

void reverse(stack<int> &s){
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, temp);
}

void print(stack<int> s){
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    cout << temp << " ";
    print(s);
    s.push(temp);
}

int main(){
    stack<int> s;
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    cout << "Before: ";
    print(s);
    cout << endl;
    reverse(s);
    cout << "After: ";
    print(s);
    cout << endl;
    return 0;
}