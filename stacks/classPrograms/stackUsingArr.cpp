#include <iostream>

using namespace std;

class Stack{
    public:
        int *arr = NULL;
        int size = 0;
        int top = -1;

        Stack(int size){
            this -> size = size;
            this -> arr = new int[size];
        }

        void push(int element){
            if(isFull()){
                cout << "Stack overflow!" << endl;
                return;
            }
            top++;
            arr[this -> top] = element;
        }

        void pop(){
            if(isEmpty()){
                cout << "Stack underflow!" << endl;
                return;
            }
            cout << "Popped element: " << arr[top] << endl;
            top--;
        }

        int peek(){
            if(isEmpty()){
                cout << "Stack is empty!" << endl;
                return -1;
            }
            return arr[top];
        }

        bool isEmpty(){
            return top == -1;
        }

        bool isFull(){
            return top >= size - 1;
        }

        int getSize(){
            return top + 1;
        }
        void print() {
            cout << "Top:  " << top << endl;
            cout << "Top element: " << peek() << endl; 
            cout << "Stack: ";
            for(int i=0; i<getSize(); i++) {
                cout << arr[i] << " ";
            }  cout << endl << endl;
        }
};

int main(){
    Stack s(5);
    // cout << s.isEmpty() << endl;
    // cout << s.isFull() << endl;
    // cout << s.getSize() << endl;
    // cout << s.peek() << endl;
    // cout << s.pop() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.print();
    return 0;
}