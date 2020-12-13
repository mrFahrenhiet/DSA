#include<bits/stdc++.h>

using namespace std;
class node {
public:
	int data;
	node *left;
	node*right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
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
void bsf(node* root) {
	queue<node *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node *temp = q.front();
		if(temp==NULL) {
			cout<<endl;
			q.pop();
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout<<temp->data<<" ";
			q.pop();
			if(temp->left) {
				q.push(temp->left);
			}
			if(temp->right) {
				q.push(temp->right);
			}
		}
	}
}
void printIn(node *root) {
	if(root==NULL) {
		return;
	}
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}
node * search(node*root,int d) {
	if(root==NULL) {
		return root;
	}
	if(d==root->data) {
		cout<<"Found";
		return root;
	}
	else if(d>root->data) {
		return search(root->right,d);
	}
	else {
		return search(root->left,d);
	}
	cout<<"Not found";
	return root;
}
node *delete_bst(node*root,int d) {
	if(root==NULL) {
		return NULL;
	}
	else if(root->data>d) {
		root->left = delete_bst(root->left,d);
		return root;
	}
	else if(root->data==d) {
		if(root->left==NULL && root->right==NULL) {
			delete root;
			return NULL;
		}
		else if(root->left==NULL && root->right!=NULL) {
			node*temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL && root->left!=NULL) {
			node*temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left!=NULL && root->right!=NULL) {
			node *replace = root->right;
			while(replace->left!=NULL) {
				replace = replace->left;
			}
			root->data = replace->data;
			root->right = delete_bst(root->right,replace->data);
			return root;
		}
	}
	else {
		root->right = delete_bst(root->right,d);
		return root;
	}

}
bool check_bst(node *root,int minv=INT_MIN,int maxv=INT_MAX) {
	if(root==NULL) {
		return true;
	}
	if(root->data>=minv && root->data<=maxv && check_bst(root->left,minv,root->data) && check_bst(root->right,root->data,maxv)) {
		return true;
	}
	return false;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    node* root = build();
    bsf(root);
    cout<<endl;
    printIn(root);
    node *x = search(root,1);
    cout<<x->data;
    node *new_root = delete_bst(root,0);
    cout<<endl;
    printIn(new_root);
    new_root = delete_bst(new_root,1);
    cout<<endl;
    printIn(new_root);
    new_root = delete_bst(new_root,5);
    cout<<endl;
    printIn(new_root);
    cout<<endl<<check_bst(new_root);
    return 0;

}

