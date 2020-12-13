#include<bits/stdc++.h>
using namespace std;
template <typename T>
class stack_push_eff {
private:
	queue<T> p;
	queue<T> s;

public:
	void push(int data) {
		p.push(data);
	}
	T top() {
		if(p.empty()) {
			return -1;
		}
		while(p.size()!=1) {
			s.push(p.front());
			p.pop();
		}
		int t =  p.front();
		p.pop();
		s.push(t);
		queue<int> q = p;
		p=s;
		s=q;
		return t;
	}
	void pop() {
		if(p.empty()) {
			return;
		}
		while(p.size()!=1) {
			s.push(p.front());
			p.pop();
		}
		p.pop();
		queue<int> q = p; 
        p = s; 
        s = q;
	}
	bool empty() {
		return p.empty();
	}

	
};
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    stack_push_eff<int> s;
    for(int i=0;i<5;i++) {
    	s.push(i);
    }
    // s.pop();
    s.push(5);
    // cout<<s.top();
    while(!s.empty()) {
    	cout<<s.top()<<" ";
    	s.pop();
    }
    return 0;

}