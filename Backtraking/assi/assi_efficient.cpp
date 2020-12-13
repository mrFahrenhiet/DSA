#include <bits/stdc++.h>
using namespace std;
int make_nos(int n) {
	if(n==1) {
		return 2;
	}
	if(n==2) {
		return 3;
	}
	return make_nos(n-2)+make_nos(n-1);
}
int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,t;
    cin>>t;
    for(int ca=0;ca<t;ca++) {
        cin>>n;
        int s = make_nos(n);
        cout<<"#"<<ca+1<<" : "<<s<<endl;
    }
}