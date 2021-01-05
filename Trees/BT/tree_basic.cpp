#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node * right;
	node(int d) {
		this->data = d;
		this->left = NULL;
		this->right = NULL;
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
void printPre(node *root) {
	if(root==NULL) {
		return;
	}
	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
}
void printPreItrative(node *root) {
	stack<node*> s;
	while(true) {
		while(root) {
			s.push(root);
			cout<<root->data<<endl;
			root = root->left;
		}
		if(s.empty()) return;
		else {
			root = s.top();
			s.pop();
			root = root->right;
		}
	}
}
void printInItrative(node* root) {
	stack<node*> s;
	while(true) {
		while(root) {
			s.push(root);
			root = root->left;
		}
		if(s.empty()) return;
		else {
			root = s.top();
			cout<<root->data<<endl;
			s.pop();
			root = root->right;
		}
	}
}

void printPost(node *root) {
	if(root==NULL) {
		return;
	}
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
}
void printIn(node *root) {
	if(root==NULL) {
		return;
	}
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}
int find_height(node *root) {
	if(root==NULL) {
		return 0;
	}
	int ls = find_height(root->left);
	int rs = find_height(root->right);
	int h =  max(ls,rs)+1;
	return h; 
}
void printLev(node *root,int k) {
	if(root==NULL) {
		return;
	}
	if(k==1) {
		cout<<root->data<<" ";
		return;
	}
	printLev(root->left,k-1);
	printLev(root->right,k-1);
	
	return;
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
int no_of_nodes(node*root) {
	if(root==NULL) {
		return 0;
	}
	int l = no_of_nodes(root->left);
	int r = no_of_nodes(root->right);
	return l+r+1;
}
int sum_of_node(node*root) {
	if(root==NULL) {
		return 0;
	}
	int l = sum_of_node(root->left);
	int r = sum_of_node(root->right);
	return l+r+root->data;
}
int diameter(node *root) {
	int maxi,m;
	if(root==NULL) {
		return 0;
	}
	int h1 = find_height(root->left);
	int h2 = find_height(root->right);
	int d = h1+h2;
	int l = diameter(root->left);
	int r = diameter(root->right);
	m = max(l,r);
	maxi = max(d,m);
	return maxi;
}
class Pair {
public:
	int h;
	int d;
};
Pair diameter_eff(node*root) {
	Pair p;
	if(root==NULL) {
		p.h = p.d =0;
		return p;
	}
	Pair left = diameter_eff(root->left);
	Pair right = diameter_eff(root->right);
	p.h = max(left.h,right.h)+1;
	p.d = max(left.h+right.h,max(left.d,right.d));
	return p;

}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    node *root = bulid();
    //printPre(root);
    //printInItrative(root);
    // cout<<endl;
    // printPost(root);
    // cout<<endl;
    // printIn(root);
    // cout<<endl;
    int h = find_height(root);
    // cout<<h<<endl;
    for(int i=h;i>=0;i--) {
    	printLev(root,i);
    	cout<<endl;
    }
    // cout<<endl;
    // bsf(root);
    // int count = no_of_nodes(root);
    // int sum = sum_of_node(root);
    // cout<<count<<" "<<sum;
    // Pair x = diameter_eff(root);
    // cout<<x.d;
    return 0;

}