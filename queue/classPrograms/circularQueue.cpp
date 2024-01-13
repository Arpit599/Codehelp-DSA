#include <iostream>

using namespace std;

class Cqueue{
    int size;
    int *arr;
public:
    int front;
    int rear;
    Cqueue(int size){
        arr = new int[size];
        front = -1;
        rear = -1;
        this -> size = size;
    }

    void push(int element){
        if(isFull()){
            cout << "Queue is full!"<< endl;
        }
        else if(isEmpty()){
            front++;
            rear++;
            arr[rear] = element;
        }
        else if(rear == size - 1 && front != 0){
            rear = 0;
            arr[rear] = element;
        }
        else {
            rear++;
            arr[rear] = element;
        }
    }

    void pop(){
        if(isEmpty()){
            cout << "Queue is empty!"<< endl;
        }
        else if(front == rear){
            arr[front] = 0;
            front = -1;
            rear = -1;
        } 
        //🔴 Ye condition ka koi zrurt ni tha, yaha glti ki thi...pop operation mein kyu check krna rear 0 hai ya ni
        // else if(front == size - 1 && rear != 0){
        else if(front == size - 1){
            arr[front] = 0;
            front = 0;
        }
        else {
            arr[front] = 0;
            front++;
        }
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFull(){
        return (front == 0 && rear == size - 1) || rear == front - 1;
    }

    void print(){
        if(isEmpty()){
            cout << "Queue is empty, nothing to print!" << endl;
            return;
        }
        for(int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};


int main(){
    Cqueue cq(2);
    while(true){
        int operation;
        cout << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. getFront" << endl;
        cout << "4. getRear" << endl;
        cout << "5. Print" << endl;
        cout << "6. front idx" << endl;
        cout << "7. rear idx" << endl;
        cout << "Enter operation: ";
        cin >> operation;
        cout << endl;

        switch(operation){
            case 1: 
            {
                int element;
                cout << "Enter element: ";
                cin >> element;
                cq.push(element);
                break;
            }
            case 2:
            {
                cq.pop();
                break;
            }
            case 3:
            {
                cout << "Front element: "<< cq.getFront() << endl;
                break;
            }
            case 4:
            {
                cout << "Rear element: "<< cq.getRear() << endl;
                break;
            }
            case 5:
            {
                cq.print();
                break;
            }
            case 6:
            {
                cout << "Front idx: "<< cq.front << endl;
                break;
            }
            case 7:
            {
                cout << "Rear idx: "<< cq.rear << endl;
                break;
            }
            default:
                cout << "Invalid operation!";
                break;
        }
    }
    return 0;
}