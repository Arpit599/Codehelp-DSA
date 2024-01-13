#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(){
            this->data = 0;
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

int getLength(Node* &head){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node *newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        Node* newNode = new Node(data);
        tail -> next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int pos){
    Node *temp = head;
    if(pos == 1) insertAtHead(head, tail, data);
    else if (pos + 1 == getLength(head)) insertAtTail(head, tail, data);
    else{
        Node *prev = NULL;
        Node *curr = head;

        while(pos != 1){
            prev = curr;
            curr = curr -> next;
            pos--;
        }
        Node *newNode = new Node(data);
        prev -> next = newNode;
        newNode -> next = curr;
    }
}

void print(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    // insertAtHead(head, tail, 1);
    // insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 4);
    // insertAtTail(head, tail, 5);
    insertAtPosition(head, tail, 69, 1);
    insertAtPosition(head, tail, 70, 1);
    insertAtPosition(head, tail, 72, 2);
    insertAtPosition(head, tail, 75, 4);
    print(head);
    cout << endl;
    return 0;
}