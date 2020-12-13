#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> &s,int x) {
	if(s.empty()) {
		s.push(x);
		return;
	}
	int g = s.top();
	s.pop();
	insert_at_bottom(s,x);
	s.push(g);
}
void stack_rev_rec(stack<int> &s) {
	if(s.empty()) {
		return;
	}
	int x = s.top();
	s.pop();
	stack_rev_rec(s);
	insert_at_bottom(s,x);
}

void stack_rev(stack<int> s) {
	stack<int> s2;
	int n = s.size();
	for(int i=0;i<s.size();i++) {
		int no = s.top();
		s.pop();
		for(int j=0;j<(n-i-1);j++) {
			int num = s.top();
			s2.push(num);
			s.pop();
		}
		s.push(no);
		for(int j=0;j<(n-i-1);j++) {
			int num = s2.top();
			s.push(num);
			s2.pop();
		}
	}
	
	while(!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return;

}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    stack<int> s;
    for(int i= 0;i<10;i++) {
    	s.push(i);
    }
    stack_rev_rec(s);
    while(!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
    return 0;

}