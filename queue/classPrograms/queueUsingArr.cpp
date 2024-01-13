#include <iostream>

using namespace std;

class Queue{
    int *arr;
    int size;
    int front;
    int rear;
public:
    Queue(int size){
        arr = new int[size];
        front = -1;
        rear = -1;
        this -> size = size;
    }

    void push(int element){
        if(isFull()){
            cout << "Queue is full!"<< endl;
            return;
        }
        if(isEmpty()){
            front++;
            rear++;
            arr[rear] = element;
        } else {
            rear++;
            arr[rear] = element;
        }
    }

    void pop(){
        if(isEmpty()){
            cout << "Queue is empty!"<< endl;
            return;
        }
        if(front == rear){
            arr[front] = 0;
            front = -1;
            rear = -1;
        } else {
            arr[front] = 0;
            front++;
        }

    }

    int getfront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFull(){
        return rear == size - 1;
    }

    void print(){
        if(isEmpty()){
            cout << "Queue is empty, nothing to print!" << endl;
            return;
        }
        for(int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front element: "<< q.getfront() << endl;
    q.push(4);
    q.push(5);
    q.push(6);
    cout << "Front element: "<< q.getfront() << endl;
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    cout << "Front element: "<< q.getfront() << endl;
    q.push(100);
    q.print();
    cout << "Front element: "<< q.getfront() << endl;
    return 0;
}