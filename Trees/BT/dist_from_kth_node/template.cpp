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
node *Build(int ino[],int pre[],int s,int e) {
	static int i=0;
	if(s>e) {
		return NULL;
	}
	node *root = new node(pre[i]);
	int index = -1;
	for(int j=s;j<=e;j++) {
		if(ino[j]==pre[i]) {
			index = j;
		}
	}
	i++;
	root->left = Build(ino,pre,s,index-1);
	root->right = Build(ino,pre,index+1,e);
	return root;
}
void percolate_down(node* root,int k,vector<int> &ans) {
    if(!root || k<0) {
        return;
    }
    if(k==0) {
        ans.push_back(root->data);
        return;
    }
    percolate_down(root->left,k-1,ans);
    percolate_down(root->right,k-1,ans);
}
int dist_from_node(node* root,int target,int k,vector<int> &ans) {
    if(!root) {
        return -1;
    }
    else if(root->data==target) {
        percolate_down(root,k,ans);
        return 1;
    }
    else {
        int l = dist_from_node(root->left,target,k,ans);
        if(l!=-1) {
            if(l==k) {
                ans.push_back(root->data);
            }
            else {
                percolate_down(root->right,k-l-1,ans);
            }
            return l+1;
        }
        int r = dist_from_node(root->right,target,k,ans);
        if(r!=-1) {
            if(r==k) {
                ans.push_back(root->data);
            }
            else {
                percolate_down(root->left,k-r-1,ans);
            }
            return r+1;
        }
    }
    return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n1;
    cin>>n1;
    int preo[n1];
    for(int pre=0;pre<n1;pre++) {
    	cin>>preo[pre];
    }
    int ino[n1];
    for(int in=0;in<n1;in++) {
    	cin>>ino[in];
    }
    node *root = Build(ino,preo,0,n1-1);
    vector<int> ans;
    int t;
    cin>>t;
    while(t--) {
        int target,k;
        cin>>target>>k;
        int x = dist_from_node(root,target,k,ans);
		if(ans.size()==0) {
			cout<<0;
		}
		else {
			sort(ans.begin(),ans.end());
			for(auto itr: ans) {
            	cout<<itr<<" ";
        	}
		}
        cout<<endl;
        ans.clear();
    }
    return 0;
}