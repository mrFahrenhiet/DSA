#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class node {
    public:
        int data;
        node *next;
        node(int d) {
            data = d;
            next = NULL;
        }
};
void intsert_at_head(node *&head,int data) {
    node *n = new node(data);
    n->next = head;
    head = n;
    return;
}
void insert_at_end(node *head,int data) {
	node *tail = head;
	while(tail->next!=NULL) {
		tail=tail->next;
	}
	node *n = new node(data);
	tail->next = n;
	n->next=NULL;
	return;
}
void build(node* &head,int data) {
    if(head==NULL) {
        intsert_at_head(head,data);
    }
    else {
        insert_at_end(head,data);
    }
    return;
}

void print(node *head) {
    while(head!=NULL) {
		cout<<head->data<<"->";
		head = head->next;
    }
    cout<<endl;
    return;
}
node* k_rev(node* head,int k) {
	node* p = head;
	node* q = NULL;
	node* nn = NULL;
	int i = 0;
	while(p && i<k) {
		i++;
		nn = p->next;
		p->next = q;
		q = p;
		p = nn;
	}

	if(nn)
		head->next = k_rev(nn,k);

	return q;
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
    node* head = NULL;
    for(int i=0;i<n;i++) {
    	int no;
    	cin>>no;
    	build(head,no);
    }
    print(head);
    node* rev = k_rev(head,3);
    print(rev);
    return 0;

}