#include<bits/stdc++.h>
using namespace std;
class Node {
public:
	char data;
	unordered_map<char, Node*> children;
	bool terminal;
	int count;

	Node(char d) {
		this->data = d;
		this->terminal = false;
		this->count = 1;
	}
};

class Trie {
	Node *root;
	int cnt;
public:
	Trie() {
		this->root = new Node('\0');
		this->cnt = 0;
	}
	void insert(char *w) {
		Node *temp=root;
		for(int j=0;w[j]!='\0';j++) {
			char ch = w[j];
			if(temp->children.count(ch)) {
				temp = temp->children[ch];
				temp->count++;
			}
			else {
				Node *n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;
		this->cnt++;
	}

	bool find(char *w) {
		Node *temp=root;
		for(int j=0;w[j]!='\0';j++) {
			char ch = w[j];
			if(temp->children.count(ch)==0) {
				return false;
			}
			else {
				temp = temp->children[ch];
			}
		}
		return temp->terminal;
	}
	void prefix(char *w) {
		Node *temp = root;
		char p[100];
		int j = 0;
		for(int i=0;w[i]!='\0';i++) {
			char ch = w[i];
			temp = temp->children[w[i]];
			p[j] = ch;
			if(temp->count==1) {
				p[j+1] = '\0';
				cout<<p<<" ";
				cout<<endl;
				return;
			}
			else {
				j++;
			}
		}
		return;

	}
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Trie t;
    char words[][20] = {"zebra","dog","dove","duck","zebras"};
    for(int i=0;i<5;i++) {
    	t.insert(words[i]);
    }
    for(int i=0;i<5;i++) {
    	t.prefix(words[i]);
    }
    return 0;

}