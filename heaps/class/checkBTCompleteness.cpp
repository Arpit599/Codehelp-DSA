#include <iostream>
#include<queue>
using namespace std;

class Node{
  public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};


//it returns root node of the created tree
Node* createTree() {
  cout << "enter the value for Node: " << endl;
  int data;
  cin >> data;

  if(data == -1) {
	return NULL;
  }
  //Step1: create Node
  Node* root = new Node(data);
  //Step2: Create left subtree
  cout << "left of Node: " << root->data << endl;
  root->left = createTree();
  //Step3: Craete right subtree
  cout << "right of Node: " << root->data << endl;
  root->right = createTree();
  return root;
}

bool isCompleteBT(Node* root){
  queue<Node*> q;
  q.push(root);
  bool nullFound = false;

  while(!q.empty()){
    Node* front = q.front();
    q.pop();
    if(front == NULL){
      nullFound = true;
    }
    else{
      if(nullFound) return false;
      q.push(front -> left);
      q.push(front -> right);
    }
  }
  return true;
}

int main(){
    Node* root = createTree();
    bool ans = isCompleteBT(root);
    cout << "BT is complete: " << ans << endl;
    return 0;
}