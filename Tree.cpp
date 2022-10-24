#include <iostream>
#include <queue>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node (int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp==NULL) {
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        } else {
            cout<<temp->data<<" ";
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
}

node* buildTree(node *root) {
    cout<<"Enter data: ";
    int x;
    cin>>x;
    if(x==-1) {
        return NULL;
    }
    node* cur = new node(x);
    root = cur;

    cout<<"Enter data for left of "<<x<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<x<<endl;
    root->right = buildTree(root->right);

    return root;
}

int main () {
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    return 0;
}