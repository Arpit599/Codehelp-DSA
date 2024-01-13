#include <iostream>
#include <stack>
using namespace std;

void insertAtCorrectPosition(stack<int> &s, int ele){
    if(s.empty() || ele >= s.top()){
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtCorrectPosition(s, ele);
    s.push(temp);
}

void sort(stack<int> &s){
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    sort(s);
    insertAtCorrectPosition(s, temp);
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
    s.push(5);
    s.push(2);
    s.push(6);
    s.push(1);
    s.push(4);
    s.push(3);
    cout << "Before: ";
    print(s);
    cout << endl;
    sort(s);
    cout << "After: ";
    print(s);
    cout << endl;
    return 0;
}