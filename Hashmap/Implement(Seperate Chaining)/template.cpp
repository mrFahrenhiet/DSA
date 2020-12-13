#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class Node {
public:
	string key;
	T val;
	Node<T> *next;

	Node(string key, T val) {
		this->key = key;
		this->val = val;
		this->next = NULL;
	}
	~Node() {
		if(next!=NULL) {
			delete next;
		}
	}
};
template<typename T>
class Hashtable {
private:
	Node<T>** table;
	int cur_size;
	int table_size;

	int hash_fn(string key) {
		int p=1;
		int idx = 0;
		for(int j=0;j<key.length();j++) {
			idx += (key[j]*p)%table_size;
			idx = idx%table_size;
			p = (p*27)%table_size;
		}
		return idx;
	}
	void reshash() {
		Node<T>** o_table = table;
		int o_table_size = table_size;
		table_size = 2*table_size+3;
		table = new Node<T>*[table_size];
		cur_size = 0;
		for(int i=0;i<table_size;i++) {
			table[i] = NULL;
		}
		for(int i=0;i<o_table_size;i++) {
			Node<T> *temp = o_table[i];
			while(temp!=NULL) {
				insert(temp->key,temp->val);
				temp = temp->next;
			}
			if(o_table[i]!=NULL) {
				delete o_table[i];
			}
		}
		delete [] o_table;
		return;
	}

public:
	Hashtable(int ts=7) {
		table_size = ts;
		table = new Node<T>*[table_size];
		cur_size = 0;
		for(int i=0;i<table_size;i++) {
			table[i] = NULL;
		}
	}

	void insert(string key, T val) {
		int idx = hash_fn(key);
		Node<T>*n = new Node<T>(key,val);
		n->next = table[idx];
		table[idx] = n;
		cur_size++;
		float lf = cur_size/(1.0*table_size);
		if(lf>0.7) {
			reshash();
		}
		return;
	}

	void print() {
		for(int i=0;i<table_size;i++) {

			cout<<"Bucket "<<i<<"->";
			Node<T>*temp = table[i];
			while(temp!=NULL) {
				cout<<"("<<temp->key<<", "<<temp->val<<")"<<"->";
				temp = temp->next;
			}
			cout<<endl;
		}
		return;
	}

	T search(string key) {
		int idx = hash_fn(key);
		Node<T>*temp = table[idx];
		while(temp!=NULL) {
			if(temp->key==key) {
				return temp->val;
			}
			temp = temp->next;
		}
		return -1;
	}

	void erase(string key) {
		int idx = hash_fn(key);
		Node<T>*temp = table[idx];
		cout<<endl<<temp->key;
		Node<T>*temp2 = NULL;
		while(temp!=NULL) {
			if(temp->key==key) {
				if(temp2!=NULL) {
					temp2->next = temp->next;
					temp->next = NULL;
					delete temp;
				}
				else {
					cout<<"NULL"<<endl<<endl;
					temp2 = temp;
					temp2 = temp2->next;
					temp->next = NULL; 
					delete temp;
				}
			}
			temp2 = temp;
			temp = temp->next;
		}
	}
};
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Hashtable<int> h;
    h.insert("pepe", 88);
    h.insert("koke",90);
    h.insert("dog",56);
    h.insert("god",112);
    h.insert("bat",12);
    h.insert("tab",5);
    h.insert("tabeta",15);
    h.insert("batman",235);
    h.print();
    int x = h.search("god");
    h.erase("god");
    cout<<endl;
    h.print();
    return 0;

}