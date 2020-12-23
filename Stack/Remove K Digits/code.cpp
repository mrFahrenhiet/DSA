#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string removeKDigits(string s, int k) {
	if(s.size()<=k) return "0";
	string res;
	for(auto digit: s) {
		while(res.size() and res.back()>digit and k) {
			res.pop_back();
			k--;
		}
		if(res.size() or digit!='0') res.push_back(digit);
	}
	while(res.size() and k) {
		res.pop_back();
		k--;
	}
	return res.size()?res:"0";
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin>>s;
    int k;
    cin>>k;
    string rem = removeKDigits(s, k);
    cout<<rem<<endl;
    return 0;

}