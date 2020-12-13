#include <bits/stdc++.h>
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
//Head passed by refference as changes are to be updated
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
void insert_at_anywhere(node *head,int data,int pos) {
	node *temp1=head;
	node *temp2;
	int i=0;
	while(i<pos && temp1!=NULL) {
		temp2 = temp1;
		temp1=temp1->next;
		i++;
	}
	node *n = new node(data);
	temp2->next = n;
	n->next = temp1;
	return;
}
void delete_from_front(node *&head) {
	node *t = head;
	head = head->next;
	delete t;
	return;
}
void delete_from_end(node *head) {
	node *tail = head;
	node*t;
	while(tail->next!=NULL) {
		t=tail;
		tail = tail->next;
	}
	t->next=NULL;
	delete tail;
	return;
}
void delete_from_middle(node *head,int pos) {
	node *t1 = head;
	node*t2;
	int i=0;
	while(t1->next!=NULL && i<pos) {
		t2=t1;
		t1 = t1->next;
		i++;
	}
	t2->next=t1->next;
	delete t1;
	return;
}
//Head passed by value as changes are not to be updated and changes not to be reflected in main
void print(node *head) {
    while(head!=NULL) {
		cout<<head->data<<"->";
		head = head->next;
    }
    cout<<endl;
    return;
}
int  is_present_give_index(node*head,int key) {
	node*t = head;
	int o=0;
	while(t!=NULL) {
		if(t->data == key) {
			return o;
		}
		o++;
		t=t->next;
	}
	return -1;
}
//Reverse LL
void rev_ll(node *&head) {
	node *p=NULL;
	node *n;
	node *c = head;
	while(c!=NULL) {
		n = c->next;
		c->next = p;
		p = c;
		c=n;
	}
	head = p;
}
node* rev_ll_rec(node* head) {
	if(head->next==NULL) {
		return head`;
	}
	node* p = rev_ll_rec(head->next);
	node* t = head->next;
	head->next = NULL;
	t->next = head;
	return p;
}
int kth_node_from_end(node *head,int k) {
	node*f=head;
	node*s=head;
	int i=0;
	while(f!=NULL) {
		if(i<k) {
			f=f->next;
			i++;
		}
		f=f->next;
		s=s->next;
	}
	return s->data;
}

//Runner Technique
node * find_mid(node *head) {
	node *slow = head;
	node *fast = head->next;
	while(fast!=NULL && fast->next!=NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* mergeLL(node *a,node *b) {
	if(a==NULL) {
		return b;
	}
	else if(b==NULL) {
		return a;
	}
	node *c;
	if(a->data<b->data) {
		c = a;
		c->next = mergeLL(a->next,b);
	}
	else {
		c = b;
		c->next = mergeLL(a,b->next);
	}
	return c;

}
node* merge_sort(node*head) {
	if(head->next==NULL|| head==NULL) {
		return head;
	}
	node* mid = find_mid(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	a = merge_sort(a);
	b = merge_sort(b);

	node* c = mergeLL(a,b);
	return c;
}

//Cycle Detection
bool is_floyd_cycle(node *head) {
	node *slow = head;
	node *fast = head->next;
	while(fast!=NULL && fast->next!=NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow) {
			return true;
		}
	}
	return false;
}

node *remove_cycle(node *head) {
	if(!is_floyd_cycle(head)) {
		cout<<"Not Cyclic"
		return head;
	}
	node *slow = head;
	node *fast = head->next;
	while(fast!=NULL && fast->next!=NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow) {
			break;
		}
	}
	slow=head;
	node *start,prev;
	while(fast!=NULL && fast->next!=NULL) {
		prev = fast;
		fast=fast->next;
		slow=slow->next;
		if(slow==fast) {
			start = slow;
			prev->next = NULL;
		}
	}
	return start;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    // node *head1 = NULL;
    // node *head2 = NULL;
    node *head = NULL;
    intsert_at_head(head,27);
    intsert_at_head(head,21);
    intsert_at_head(head,24);
    intsert_at_head(head,45);
    intsert_at_head(head,33);
    intsert_at_head(head,18);
    insert_at_end(head,52);
    insert_at_anywhere(head,9,3);
    intsert_at_head(head,99);
    print(head);
    cout<<is_floyd_cycle(head);
    // intsert_at_head(head,1);
    // intsert_at_head(head,4);
    // intsert_at_head(head,0);
    // intsert_at_head(head,2);
    // intsert_at_head(head,3);
    // intsert_at_head(head,9);
    // intsert_at_head(head,8);
    // intsert_at_head(head,-1);
    // print(head);
    // node*x = merge_sort(head);
    // print(x);
    // delete_from_front(head);
    // delete_from_end(head);
    // delete_from_middle(head,2);
    // print(head);
    // int key;
    // cin>>key;
    // int x = is_present_give_index(head,key);
    // cout<<x;
    // rev_ll(head);
    // print(head);
    // cout<<kth_node_from_end(head,1);
    // intsert_at_head(head1,1);
    // insert_at_end(head1,3);
    // insert_at_end(head1,4);
    // insert_at_end(head1,7);
    // print(head1);
    // intsert_at_head(head2,0);
    // insert_at_end(head2,2);
    // insert_at_end(head2,8);
    // insert_at_end(head2,10);
    // print(head2);
    // node *m = mergeLL(head1,head2);
    // print(m);
    return 0;

}