#include<bits/stdc++.h>
using namespace std;
class Node {
public:
	char data;
	unordered_map<char, Node*> children;
	bool terminal;

	Node(char d) {
		this->data = d;
		this->terminal = false;
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
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Trie t;
    char words[][200] = {"https://online.codingblocks.com","https://online.codingblocks.com/app","https://www.google.com","https://www.nodejsera.com/nodejs-tutorial-day1-thebeginning.html","https://github.com/","https://github.com/mrFahrenhiet"};
    char w[200];
    cin>>w;
    for(int i=0;i<6;i++) {
    	t.insert(words[i]);
    } 
    if(t.find(w)) {
		cout<<"Present"<<endl;
    }
    else {
    	cout<<"Not Present"<<endl;
    }
    return 0;

}