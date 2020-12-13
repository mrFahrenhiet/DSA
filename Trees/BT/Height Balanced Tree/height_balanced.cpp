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
int find_height(node *root) {
	if(root==NULL) {
		return 0;
	}
	int ls = find_height(root->left);
	int rs = find_height(root->right);
	int h =  max(ls,rs)+1;
	return h; 
}
class hb_pair {
public:
	int h;
	bool b;
};
hb_pair is_balanced(node *root) {
	hb_pair p;
	if(root==NULL) {
		p.h=0;
		p.b=true;
		return p;
	}
	hb_pair left= is_balanced(root->left);
	hb_pair right = is_balanced(root->right);
	p.h = max(left.h,right.h)+1;
	if(abs(left.h-right.h)<=1 && left.b && right.b) {
		p.b = true;
	}
	else {
		p.b = false;
	}
	return p;


}
node * build_balanced_tree(int a[],int s,int e) {
	if(s>e) {
		return NULL;
	}
	int m = (s+e)/2;
	node *root =  new node(a[m]);
	root->left = build_balanced_tree(a,s,m-1);
	root->right = build_balanced_tree(a,m+1,e);
	return root;
}
void printIn(node *root) {
	if(root==NULL) {
		return;
	}
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int a[7] = {0,1,2,3,4,5,6};
    node *root = build_balanced_tree(a,0,6);
   	if(!is_balanced(root).b){
   		cout<<"tree not balanced";
   	}
   	else {
   		cout<<"tree balanced"<<endl;
   		printIn(root);

   	}
    return 0;

}