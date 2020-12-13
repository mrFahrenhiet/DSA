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

class Solution
{
public:
    node* head;
    node* prev;
    
    void bt2ll(node* root) {
        if(!root)
            return;
        bt2ll(root->left);
        if(prev==NULL)
            head=root;
        else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        bt2ll(root->right ) 
    }
    
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    return 0;
}