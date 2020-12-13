#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Stack
{
	private:
		vector<T> v;
	public:
		void push(T data) {
			v.push_back(data);
		}
		bool is_empty() {
			return v.size()==0;
		}
		void pop() {
			if(!this.is_empty())
				v.pop_back();
		}
		T top() {
			v[v.size()-1];
		}
	
};
void stack_rev(Stack<int> s) {
	Stack<int> s2;
	while(!s.is_empty()) {
		int no = s.top();
		s2.push(no);
		s.pop();
	}
	while(!s2.is_empty()) {
		cout<<s2.top()<<" ";
		s2.pop();
	}
	return;

}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Stack<int> s;
    for(int i= 0;i<10;i++) {
    	s.push(i);
    }
    stack_rev(s);
    while(!s.is_empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
    return 0;

}