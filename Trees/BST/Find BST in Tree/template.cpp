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
node *build(int in[],int pre[],int s,int e) {
	static int i =0;
	if(s>e) {
		return NULL;
	}
	node *root = new node(pre[i]);
	int index = -1;
	for(int j=s;j<=e;j++) {
		if(pre[i]==in[j]) {
			index = j;
			break;
		}
	}
	i++;
	root->left = build(in,pre,s,index-1);
	root->right = build(in,pre,index+1,e);
	return root;
}
void preo(node *root) {
	if(!root) {
		return;
	}
	cout<<root->data<<" ";
	preo(root->left);
	preo(root->right);
	return;
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
int find_height(node *root) {
	if(root==NULL) {
		return 0;
	}
	int ls = find_height(root->left);
	int rs = find_height(root->right);
	int h =  ls+rs+1;
	return h; 
}int bst_in_bt(node *root) {
	if(!root) {
		return 0;
	}
	if(check_bst(root)) {
		return find_height(root);
	}
	int l = bst_in_bt(root->left);
	int r = bst_in_bt(root->right);
	return max(l,r);
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    int pre[1005],in[1005];
    for(int i=0;i<n;i++) {
    	cin>>pre[i];
    }
    for(int i=0;i<n;i++) {
    	cin>>in[i];
    }
    node *root = build(in,pre,0,n-1);
    // preo(root);
    cout<<bst_in_bt(root);
    return 0;

}