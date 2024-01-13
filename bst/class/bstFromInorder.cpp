#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
    TreeNode(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

TreeNode* createBST(vector<int> inorder, int start, int end){
    if(start <= end){
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(inorder[mid]);
        node -> left = createBST(inorder, start, mid - 1);
        node -> right = createBST(inorder, mid + 1, end);
        return node;
    }
    else return NULL;
}


void levelOrderTraversal(TreeNode* root){
    if(root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();
        if(front == NULL){
            if(!q.empty()) q.push(NULL);
            cout << endl;
        }
        else {
            cout << front -> data << " ";
            if(front -> left) q.push(front -> left);
            if(front -> right) q.push(front -> right);
        }
    }
}


int main(){
    vector<int> inorder = {20, 30, 40, 50, 70, 80, 100};
    TreeNode* root = createBST(inorder, 0, inorder.size() - 1);
    levelOrderTraversal(root);
    return 0;
}