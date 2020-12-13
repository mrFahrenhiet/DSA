#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node *left;
	node *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
node *build() {
	int d,e;
	cin>>d>>e;
	node *root = new node(d);
	if(e==0) {
		root->left==NULL;
		root->right==NULL;
		return root;
	}
	else if(e==1) {
		root->left = build();
		root->right = NULL;
		return root;
	}
	else if(e==2) {
		root->left = build();
		root->right = build();
		return root;
	}
} 
void bsf(node* root) {
	queue<node *> q;
	q.push(root);
	q.push(NULL);
	int i=0,sum=0;
	while(!q.empty()) {
		node *temp = q.front();
		if(temp==NULL) {
			i++;
			// cout<<endl;
			q.pop();
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			if(i==2)
				sum+=q.front()->data;
			q.pop();
			if(temp->left) {
				q.push(temp->left);
			}
			if(temp->right) {
				q.push(temp->right);
			}
		}
	}
	cout<<sum;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    node *root = build();
    int x;
    cin>>x;
    bsf(root);

    return 0;

}