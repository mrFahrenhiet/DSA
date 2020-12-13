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
node* rev_ll_rec(node* head) {
	if(head->next==NULL) {
		return head;
	}
	node* p = rev_ll_rec(head->next);
	node* t = head->next;
	head->next = NULL;
	t->next = head;
	return p;
}

bool palindrome(node* head) {
    node* e = head;
    node* t = head;
    node* p = NULL;
    node* fast = head->next;
    node* slow = head;
    int s=0;
    while(t!=NULL) {
        s++;
        t = t->next;
    }
    while(fast!=NULL && fast->next!=NULL) {
        p = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    p->next = NULL;
    node* q;
    if(s%2!=0) {
        q = slow->next;
    }
    else {
        q = slow;
    }
    q = rev_ll_rec(q);
    p = head;

    while(p!=NULL && q!=NULL) {
        if(p->data!=q->data) {
            return false;
        }
        p = p->next;
        q = q->next;
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    node* head = NULL;
    for(int i=0;i<n;i++) {
        int no;
        cin>>no;
        build(head,no);
    }
    print(head);
    cout<<palindrome(head);
}
