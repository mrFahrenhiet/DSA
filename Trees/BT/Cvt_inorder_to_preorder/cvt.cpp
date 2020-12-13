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
map<int,vector<node*> > levels(node* root) {
	map<int,vector<node*>> v;
	int i = 1;
	if(!root) {
		return v;
	}
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node* t = q.front();
		if(t==NULL) {
			i++;
			q.pop();
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			v[i].push_back(t);
			q.pop();
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
	}
	return v;
}
void left_view(node* root) {
	map<int,vector<node*> > m = levels(root);
	for(auto itr:m) {
		cout<<itr.second[0]->data<<" ";
	}
	return;
}
node *cvt(int ino[],int pre[],int s,int e) {
	static int i=0;
	if(s>e) {
		return NULL;
	}
	node *root = new node(pre[i]);
	int index = -1;
	for(int j=s;j<=e;j++) {
		if(ino[j]==pre[i]) {
			index = j;
			break;
		}
	}
	i++;
	root->left = cvt(ino,pre,s,index-1);
	root->right = cvt(ino,pre,index+1,e);
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
			if(temp->left) {
				cout<<temp->left->data<<" ";
			}
			else {
				cout<<"END ";
			}
			cout<<"=> "<<temp->data<<" <= ";
			if(temp->right) {
				cout<<temp->right->data<<" ";
			}
			else {
				cout<<" END ";
			}
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
void printPost(node *root) {
	if(root==NULL) {
		return;
	}
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
}
void printPre(node *root) {
	if(root==NULL) {
		return;
	}
	cout<<root->data<<" ";
	printPost(root->left);
	printPost(root->right);
}
void printIn(node *root) {
	if(root==NULL) {
		return;
	}
	printPost(root->left);
	cout<<root->data<<" ";
	printPost(root->right);
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n1,n2;
    cin>>n1;
    int preo[n1];
    for(int pre=0;pre<n1;pre++) {
    	cin>>preo[pre];
    }
    cin>>n2;
    int ino[n2];
    for(int in=0;in<n2;in++) {
    	cin>>ino[in];
    }
    node *root = cvt(ino,preo,0,n1-1);
    printPre(root);
    cout<<endl;
    printPost(root);
   	// printPost(root);
   	// left_view(root);
    return 0;
}