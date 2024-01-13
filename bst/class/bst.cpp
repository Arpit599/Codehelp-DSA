#include<iostream>
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

void inorder(TreeNode* root){
    if(root == NULL) return;
    inorder(root -> left);
    cout << root -> data << " -> ";
    inorder(root -> right);
}

TreeNode* insertInBST(TreeNode* root, int data){
    if(root == NULL){
        root = new TreeNode(data);
        return root;
    }

    if(root -> data < data){
        root -> right = insertInBST(root -> right, data);
    }
    if(root -> data > data){
        root -> left = insertInBST(root -> left, data);
    }
    return root;
}

void createBST(TreeNode* &root){
    int data;
    cout << "Enter data: ";
    cin >> data;
    cout << endl;
    while(data != -1){
        root = insertInBST(root, data);
        cout << "Enter data: ";
        cin >> data;
        cout << endl;
    }
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

bool searchInBST(TreeNode* root, int target){
    if(root == NULL) return false;
    if(root -> data == target) return true;

    bool left = false;
    bool right = false;
    if(target > root -> data) right = searchInBST(root -> right, target);
    if(target < root -> data) left = searchInBST(root -> left, target);
    return left || right;
}

TreeNode* convertDllToBST(TreeNode* &head, int n){
    if(head == NULL || n <= 0) return NULL;
    
    TreeNode* lst = convertDllToBST(head, n / 2);
    TreeNode* root = head;
    root -> left = lst;

    // Very important to move this head ahead, dont data
    head = head -> right;
    root -> right = convertDllToBST(head, n - (n / 2) - 1);
    return root;
}


int main(){
    // createBST(root);
    // int target;
    // cout << "Enter search value: ";
    // cin >> target;
    // cout << endl;
    TreeNode* first = new TreeNode(1);
    TreeNode* second = new TreeNode(2);
    TreeNode* third = new TreeNode(3);
    TreeNode* fourth = new TreeNode(4);
    TreeNode* fifth = new TreeNode(5);
    first -> right = second;
    second -> left = first;
    second -> right = third;
    third -> left = second;
    third -> right = fourth;
    fourth -> left = third;
    fourth -> right = fifth;
    fifth -> left = fourth;

    TreeNode* head = first;
    TreeNode* root = convertDllToBST(head, 5);
    levelOrderTraversal(root);
    inorder(root);
    cout << endl;
    // while(target != -1){
    //     cout << searchInBST(root, target) << endl;
    //     cout << "Enter search value: ";
    //     cin >> target;
    //     cout << endl;
    // }
    return 0;
}