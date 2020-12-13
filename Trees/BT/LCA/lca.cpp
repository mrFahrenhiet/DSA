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
// TC = O(n) && SC = O(1) + The code was cleaner
// Only when A and B both present
node* lca(node* root,int a,int b) {
	if(!root) {
		return NULL;
	}
	// if(root->data==a or root->data==b) {
	// 	return root;
	// }
	node* leftans = lca(root->left,a,b);
	node* rightans = lca(root->right,a,b);
	if(leftans and rightans) {
		return root;
	}
	if(leftans and !rightans) {
		return leftans;
	}
	return rightans;
}
// TC = O(2n) && SC = O(2n)
bool ancestors_list(vector<int> &ancestors,node*root,int x) {
	if(!root) {
		return false;
	}
	ancestors.push_back(root->data);
	// cout<<ancestors[0]<<" ";
	if(root->data==x) {
		return true;
	}
	else if( (root->left && ancestors_list(ancestors,root->left,x))||(root->right&& ancestors_list(ancestors,root->right,x)) ) {
		return true;
	}
	else {
		ancestors.pop_back();
		return false;
	}
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    node *root = bulid();
    // bsf(root);
    int x;
    int q;
    cin>>x>>q;
    node* ans = lca(root,x,q);
    cout<<ans->data;
    // vector<int> ancestors;
    // vector<int> q_ancestors;
    // bool p_t = ancestors_list(ancestors,root,x);
    // bool q_t = ancestors_list(q_ancestors,root,q);
    // int i=0;
    // int ans = -1;
    // while(i<ancestors.size() && i<q_ancestors.size()) {
    // 	if(ancestors[i]==q_ancestors[i]) {
    // 		ans = max(ans,i);
    // 	}
    // 	i++;
    // }
    // cout<<ancestors[ans];
    return 0;

}