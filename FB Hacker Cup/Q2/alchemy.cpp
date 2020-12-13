#include<bits/stdc++.h>
#define ll long long int
using namespace std;

map<char,int> m;
bool is_valid(string A) {
	for(int i=0;i<A.size();i++) {
		if(m.count(A[i])==0) {
			m[A[i]] = 1;
		}
		else {
			m[A[i]]++;
		}
	}
	// cout<<abs(m['A']-m['B'])<<endl;
	if(abs(m['A']-m['B'])<=1) {
		return true;
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
    int T;
    cin>>T;
    int num = 1;
    while(T--) {
    	int n;
    	cin>>n;
    	string A;
    	cin>>A;
    	cout<<"Case #"<<num<<": ";
    	if(is_valid(A))
    		cout<<"Y\n";
    	else
    		cout<<"N\n";
    	num++;
    	m.clear();
    }
    return 0;

}