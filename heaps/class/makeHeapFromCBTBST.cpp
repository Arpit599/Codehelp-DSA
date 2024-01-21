#include <iostream>
#include<queue>
#include<vector>
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


void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	//asli traversal start krete h 

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();

		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			//valid node wala case
			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
}

void getInorder(Node* root, vector<int>&in){
    if(root == NULL) return;
    getInorder(root -> left, in);
    in.push_back(root -> data);
    getInorder(root -> right, in);
}

void generateHeap(Node* root, vector<int> &inorder){
    int i = inorder.size() - 1;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();    
        front -> data = inorder[i--];
        if(front -> left) q.push(front -> left);
        if(front -> right) q.push(front -> right);
    }
}

int main(){
    Node* root = createTree();
    vector<int> inorder;
    getInorder(root, inorder);
    generateHeap(root, inorder);
    levelOrderTraversal(root);
    // cout << "BT is complete: " << ans << endl;
    return 0;
}