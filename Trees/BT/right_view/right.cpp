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

node* buildTreeLevelWise()
{
    int d;
    cin>>d;
    node* root=new node(d);
    queue <node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* f=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            f->left=new node(c1);
            q.push(f->left);
        }
        if(c2!=-1)
        {
            f->right=new node(c2);
            q.push(f->right);
        }
        

    }
    return root;
}

void print_right(node *root,int current) {
	if(root==NULL) {
		return;
	}
	static int max_visited = 0;
	if(max_visited==0 && current==0) {
		cout<<root->data<<" ";
	}
	if(current>max_visited) {
		cout<<root->data<<" ";
		max_visited = current;
	}
	print_right(root->right,current+1);
	print_right(root->left,current+1);
	return;

}
void pre_print(node *root) {
	if(root==NULL) {
		return;
	}
	cout<<root->data<<" ";
	pre_print(root->left);
	pre_print(root->right);
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

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    node *root = buildTreeLevelWise();
    print_right(root,0);
    cout<<endl;
    bsf(root);
    return 0;

}