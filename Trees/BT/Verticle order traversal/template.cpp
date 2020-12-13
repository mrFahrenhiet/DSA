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
typedef pair<node*,int> pi;
node* bulid() {
	int d;
	cin>>d;
	if(d==-1) {
		return NULL;
	}
	queue<node *> q;
	node *root = new node(d);
	q.push(root);
	while(!q.empty()) {
		node *temp = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1) {
			temp->left = new node(c1);
			q.push(temp->left);
		}
		if(c2!=-1) {
			temp->right = new node(c2);
			q.push(temp->right);
		}
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

void verticle_print(node *root, int d, map<int,vector<int>> &m) {
	if(root==NULL) {
		return;
	}
	m[d].push_back(root->data);
	verticle_print(root->left,d-1,m);
 	verticle_print(root->right,d+1,m);
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
    node *root = bulid();
    map<int,vector<int>> m;
    int d=0;
    verticle_print(root,d,m);
    for(auto it:m) {
    	cout<<"X = "<<it.first<<" = ";
    	for(auto itr:it.second) {
    		cout<<itr<<", ";
    	}
    	cout<<endl;
    }
    return 0;

}