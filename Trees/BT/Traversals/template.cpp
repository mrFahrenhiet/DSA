#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* build_tree() {
	int d;
	cin>>d;
	if(d==-1) {
		return NULL;
	}
	Node *root = new Node(d);
	root->left = build_tree();
	root->right = build_tree();
	return root;
}

Node* build_lev() {
	int d;
	cin>>d;
	if(d==-1) {
		return NULL;
	}
	Node* root = new Node(d);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1) {
			temp->left = new Node(c1);
			q.push(temp->left);
		}
		if(c2!=-1) {
			temp->right = new Node(c2);
			q.push(temp->right);
		}
	}
	return root;
}

void preOrder(Node* root) {
	stack<Node*> s;
	while(1) {
		while(root) {
			cout<<root->data<<" ";
			s.push(root);
			root = root->left;
		}
		if(s.empty()) {
			break;
		}
		else {
			root = s.top();
			s.pop();
			root = root->right;
		}
	}
}

void levOrder(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		Node* temp = q.front();
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

Node* cvt(int pre[], int ino[],int s, int e) {
	static int idx = 0;
	if(s>e) {
		return NULL;
	}
	Node* root = new Node(pre[idx]);
	int index = -1;
	for(int i=s;i<=e;i++) {
		if(ino[i]==pre[idx]) {
			index = i;
			break;
		}
	}
	idx++;
	root->left = cvt(pre,ino,s,index);
	root->right = cvt(pre,ino,index,e);
	return root;
}

void rightView(Node* root, map<int,list<int> > &rv) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int i = 1;
	while(!q.empty()) {
		Node* temp = q.front();
		if(temp==NULL) {
			i++;
			q.pop();
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			rv[i].push_back(temp->data);
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

void horizontal_dist(Node* root, map<int,list<int>> &tv,int d) {
	if(!root) {
		return;
	}
	tv[d].push_back(root->data);
	horizontal_dist(root->left,tv,d-1);
	horizontal_dist(root->right,tv,d+1);
}

pair<int,bool> is_balenced(Node* root) {
	pair<int,bool> p;
	if(!root) {
		p.first = 0;
		p.second = true;
		return p;
	}
	pair<int,bool> is_lb = is_balenced(root->left);
	pair<int,bool> is_rb = is_balenced(root->right);
	if(is_lb.second==true && is_rb.second==true && (is_lb.first-is_rb.first)>=-1) {
		p.second = true;
		p.first = max(is_lb.first,is_rb.first)+1;
	}
	return p;
}
void perculate_down(Node* root, int k, vector<int> &res) {
	if(!root) {
		return;
	}
	if(k==0) {
		res.push_back(root->data);
		return;
	}
	perculate_down(root->left,k-1,res);
	perculate_down(root->right,k-1,res);
	return;
}
int nodes_at_k(Node* root, int target, int k, vector<int> &res) {
	if(!root) {
		return -1;
	}
	if(root->data==target) {
		perculate_down(root,k,res);
		return 1;
	}
	int l = nodes_at_k(root->left,target,k,res);
	if(l!=-1) {
		if(l==k) {
			res.push_back(root->data);
		}
		else {
			perculate_down(root->right,k-l-1,res);
		}
		return l+1;
	}
	int r = nodes_at_k(root->right,target,k,res);
	if(r!=-1) {
		if(r==k) {
			res.push_back(root->data);
		}
		else {
			perculate_down(root->left,k-r-1,res);
		}
	}

}
// Node* lca2(Node* root,int a, int b) {
// 	if(!root) {
// 		return NULL;
// 	}
// 	if(root->data==a or root->data==b) {
// 		return root;
// 	}
// 	Node* l = lca2(root->left,res);
// 	Node* r = lca2(root->right,res);
// 	if((l->data==a and r->data==b) or (l->data==b and r->data==a)) {
// 		return root;
// 	}
// 	else if(l and !r) {
// 		return l;
// 	}
// 	else {
// 		return r;
// 	}
// }
// int lca(Node* root, vector<int> &res) {
// 	if(!root) {
// 		return -1;
// 	}
// 	res.push_back(res->data);
// 	int l = lca(root->left, res);
// 	int r = lca(root->right, res);
// 	if((l && r) || (root->left && root->right)) {
// 		return 1;
// 	}
// 	else {
// 		res.pop_back();
// 		return -1;
// 	}
// }
vector<int> dp(100,-1);
int max_sum_path(Node* root,int &ans) {
	if(!root) {
		return 0;
	}
	int l = max_sum_path(root->left,ans);
	int r = max_sum_path(root->right,ans);
	int sum =  max(root->data,root->data + max(l,r));
	int sum_main = max(sum,l+r+root->data);
	ans = max(ans,sum_main);
	if(dp[sum]!=-1) {
		return dp[sum];
	}
	return dp[sum] = sum;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Node* root = build_lev();
    levOrder(root);
    cout<<endl;
    // vector<int> res;
    // int k=2,target=4;
    // int x = nodes_at_k(root,target,k,res);
    // cout<<target<<"-";
    // for(auto itr: res) {
    // 	cout<<itr<<" ";
    // }
    // Node *root = build_tree();
    // levOrder(root);
    // cout<<endl;
    // pair<int,bool> x = is_balenced(root);
    // cout<<x.first<<" "<<x.second<<endl;
    // cout<<endl;
    // map<int,list<int> > rv;
    // rightView(root,rv);
    // for(auto itr: rv) {
    // 	cout<<itr.first<<"-";
    // 	for(auto it: itr.second) {
    // 		cout<<it<<" ";
    // 	}
    // 	cout<<endl;
    // }
    // cout<<endl;
    int ans = INT_MIN;
    int x= max_sum_path(root,ans);
 	cout<<ans<<endl;
 //    map<int,list<int>> tv;
 //    horizontal_dist(root,tv,0);
 //    for(auto itr: tv) {
	// cout<<itr.first<<"-";
	// for(auto it: itr.second) {
	// 	cout<<it<<" ";
	// }
	// cout<<endl;
	// }

    return 0;

}