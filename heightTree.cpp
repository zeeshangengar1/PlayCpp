#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* left, *right;
	Node(int val){
		data = val;
		left = right = NULL;
	}
}; 

// void preOrder(Node* root){
// 	if(root == NULL) return;
// 	cout << root->data << " ";
// 	preOrder(root->left);
// 	preOrder(root->right);
// }

void inORder(Node* root){
	Node *temp = root;
	stack <Node *> st;
	while(true){
		if(temp){
			st.push(temp);
			temp = temp->left;
		}else{
			if(st.empty()) return;
			auto it = st.top();st.pop();
			cout << it->data << " ";
			temp = it->right;
			
		}
	}
	cout << endl;
}

//using two stack
void postOrder(Node* root){

	if(root == NULL) return;
	stack <Node* > s1,s2;
	s1.push(root);
	while(!s1.empty()){
		auto it = s1.top(); s1.pop();
		s2.push(it);
		if(it->left) s1.push(it->left);
		if(it->right) s1.push(it->right);
	}
	while(!s2.empty()){
		cout << s2.top()->data << " ";
		s2.pop();
	}
	cout << endl;
}

//Using One stack
void postOrderUsingOneStack(Node* root){
	Node *curr, *temp;
	if(root == NULL) return;
	stack<Node* > st;
	st.push(root);
	curr = root->left;
	while(curr || !st.empty()){
		if(curr){
			st.push(curr);
			curr = curr->left;
		}else
			temp = st.top()->right;

		if(temp)
			curr = temp;
		else{
			temp = st.top();st.pop();
			cout << temp->data << " ";
			while(!st.empty() and st.top()->right == temp){
				temp = st.top();	st.pop();
				cout << temp->data << " ";
			}
		}
	}
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(7);
//    cout<<root->left->data<<" ";
	// preOrder(root); cout << endl;
	postOrderUsingOneStack(root);

}