#include<bits/stdc++.h>
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

node *build() {
	static queue<string> q;
    node* root;
    int d,i=0;
    cin>>d;
    // cout<<d<<" ";
   	root = new node(d);
    string s;
    cin>>s;
    q.push(s);
    while(s!="true") {
        cin>>s;
        q.push(s);
        i++;
        if(i==10) {
        	break;
        }
    }
    string x = q.front();
    // cout<<x<<" ";
    if(!q.empty()) {
        q.pop();
    }
    if(x=="true") {
        root->left = build();
    }
    else {
        root->left = NULL;
    }
    string x2 = q.front();
    // cout<<x2<<" ";
    if(!q.empty()) {
        q.pop();
    }
    if(x2=="true") {
        root->right = build();
    }
    else {
        root->right=NULL;
    }
    return root;
}
void printPre(node*root) {
    if(root==NULL) {
        return;
    }
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
    return;
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
void printLevRev(node *root,int k) {
    if(root==NULL) {
        return;
    }
    if(k==1) {
        cout<<root->data<<" ";
        return;
    }
    printLevRev(root->right,k-1);
    printLevRev(root->left,k-1);
    
    
    return;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    node *root = build();
    // printPre(root);
    int h = find_height(root);
    // cout<<h<<endl;
    for(int i=1;i<=h;i++) {
        if(i%2==0) {
            printLevRev(root,i);
        }
        else {
            printLev(root,i);
        }
        cout<<endl;
    }
    // if(!is_balanced(root).b){
   	// 	cout<<"false";
   	// }
   	// else {
   	// 	cout<<"true"<<endl;

   	// }
    return 0;

}