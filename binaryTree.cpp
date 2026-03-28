#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(vector<int> preorderArray, int &idx){
    idx++;
    if(preorderArray[idx]==-1) return NULL;
    
    Node* root = new Node(preorderArray[idx]);
    root->left = buildTree(preorderArray, idx);
    root->right = buildTree(preorderArray, idx);
    return root;
}

void preorder(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        if(q.front()==NULL && q.size()>1){
            cout << endl;
            q.push(NULL);
            q.pop();
            continue;
        }
        if(q.front()->left!=NULL){
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL){
            q.push(q.front()->right);
        }
        cout << q.front()->data << " ";
        q.pop();
    }
}

int main(){
    vector<int> preorderArray = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    
    int idx = -1;
    Node* root = buildTree(preorderArray, idx);
    
    preorder(root); cout << endl;
    inorder(root); cout << endl;
    postorder(root); cout << endl;
    levelorder(root); cout << endl;
    return 0;
}