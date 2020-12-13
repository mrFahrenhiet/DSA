#include<iostream>
#include<stack>
using namespace std;
bool check_balance(char a[]) {
	stack<char> s;
	int j=0;
	char ch;
	for(int i=0;a[i]!='\0';i++) {
		if(a[i]=='(' or a[i]=='{' or a[i]=='[') {
			s.push(a[i]);
			ch = s.top();
		}
		else if(a[i]==')' and ch=='(' or a[i]=='}' and ch=='{' or a[i]==']' and ch=='[' ) {
			if(s.empty()) {
				j++;
				continue;
			}
			s.pop();
		}
		else {
			return false;
		}
	}
	if(s.empty() && j==0) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    char a[50];
    cin>>a;
    if(check_balance(a)) {
    	cout<<"Yes";
    }
    else {
    	cout<<"No";
    }
    return 0;

}