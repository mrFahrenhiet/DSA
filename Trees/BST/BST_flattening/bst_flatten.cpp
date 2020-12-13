#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node *left;
	node *right;
	node(int d) {

	}
};
node* insert_bst(node *root,int no) {
	if(root==NULL) {
		return new node(no);
	}
	
	if(no<=root->data) {
		root->left = insert_bst(root->left,no);
	}
	else {
		root->right = insert_bst(root->right,no);
	}
	return root;

}
node* build() {
	int d;
	cin>>d;
	node *root =NULL;
	while(d!=-1) {
		root=insert_bst(root,d);
		cin>>d;
	}
	return root;
}

class ll {
public:
	node *head;
	node *tail;
};
ll flaten(node* root) {
	ll l;
	if(root==NULL) {
		l.head = l.tail = NULL;
	}
	if(root->left==NULL&& root->right==NULL) {
		l.head = l.tail = root;
	}
	if(root->right!=NULL && root->left==NULL) {
		ll rightl = flaten(root->right);
		root->right = rightl.head;
		l.head = root;
		l.tail = rightl.tail;
		return l;
	}
	if(root->right==NULL && root->left!=NULL) {
		ll leftl = flaten(root->left);
		leftl.tail->right = root;
		l.head = leftl.head;
		l.tail = root;
		return root;
	}
	ll leftl = flaten(root->left);
	ll rightl = flaten(root->right);
	leftl.tail->right = root;
	root->right = rightl.head;
	l.head = leftl.head;
	l.tail = rightl.tail;
	return l;

}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    return 0;

}