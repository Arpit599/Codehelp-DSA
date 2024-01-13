#include<iostream>
using namespace std;

class LinkedListNode
{
    public:
        LinkedListNode *next;
        int data;
        LinkedListNode(int data)
        { 
            this->data = data;
            this->next = NULL;
        }
};

int solve(LinkedListNode *head){
    if(head == NULL) return 1;
    int sum = head -> data + solve(head -> next);
    head -> data = sum % 10;
    return sum / 10;
}


LinkedListNode* addOneToList(LinkedListNode *head)
{
    //Write your code here
    int carry = solve(head);
    if(carry != 0) {
        LinkedListNode *newNode = new LinkedListNode(carry);
        newNode -> next = head;
        head = newNode;
    }
    return head;
}

int main(){
    LinkedListNode *one = new LinkedListNode(9);
    LinkedListNode *two = new LinkedListNode(9);
    LinkedListNode *three = new LinkedListNode(9);

    one -> next = two;
    two -> next = three;

    LinkedListNode *head = one;
    head = addOneToList(head);

    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
    return 0;
}