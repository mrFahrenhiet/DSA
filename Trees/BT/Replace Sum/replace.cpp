#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node * right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* bulid() {
	int d;
	cin>>d;
	if(d==-1) {
		return NULL;
	}
	node *root = new node(d);
	root->left = bulid();
	root->right = bulid();
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
int replace_sum(node *root) {
	if(root==NULL) {
		return 0;
	}
	if(root->left==NULL && root->right==NULL) {
		return root->data;
	}
	int l = replace_sum(root->left);
	int r = replace_sum(root->right);
	int temp = root->data;
	root->data = l+r;
	return root->data +temp;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    node *root = bulid();
    replace_sum(root);
    bsf(root);

    return 0;

}