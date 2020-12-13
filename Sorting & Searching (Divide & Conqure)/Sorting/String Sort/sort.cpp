#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

bool comp(string &s1,string &s2) {
	int n = min(s1.size(),s2.size());
	int count=0;
	for(int i=0;i<n;i++) {
		if(s1[i]==s2[i]) {
			count++;
		}
	}
	if(count==n) {
		return s1>s2;
	}
	return s1<s2;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++) {
    	cin>>a[i];
    }
    sort(a,a+n, comp);
    for(int i=0;i<n;i++) {
    	cout<<a[i]<<endl;
    }
	return 0;
}