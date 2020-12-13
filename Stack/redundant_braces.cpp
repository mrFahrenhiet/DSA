#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool is_redundant(string A) {
	stack<char> s;
	for(auto i: A) {
		if(i!=')') {
			s.push(i);
		}
		else {
			bool checkOp = false;
			if(s.empty()) {
				return false;
			}
			if(s.top()=='(') {
				return true;
			}
			while(s.top()!='(') {
				string top = s.top();
				if(top=='+' or top=='-' or top=='*' or top=='/') {
					checkOp = true;
				}
				s.pop();
			}
			s.pop();
			if(!checkOp) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
    	string s;
    	cin>>s;
    	cout<<is_redundant(s)<<endl;
    }
    return 0;

}