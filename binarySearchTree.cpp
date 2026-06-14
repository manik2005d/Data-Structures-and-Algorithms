#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;
    for (int val : arr){
        root = insert(root, val);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int val){
    if(root==NULL) return false;

    if(root->data==val){
        return true;
    }else if(root->data>val){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
}

Node* getInorderSuccessor(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Case 1 & 2: Node has 0 or 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }else{
            // Case 3: Node has 2 children
            Node* temp = getInorderSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    inorder(root);
    cout << endl << search(root, 7);
}