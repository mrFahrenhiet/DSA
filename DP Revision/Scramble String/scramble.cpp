#include <bits/stdc++.h>
using namespace std;
#define ll long long int
unordered_map<string, bool> dp;
bool scramble_string(string a, string b) {
	if(a.compare(b)==0) return true;
	if(a.length() <= 1) return false;
	if(dp.count(a+b)) return dp[a+b];
	for(int i=1;i<a.length();i++) {
		bool cond1 = scramble_string(a.substr(0, i), b.substr(b.length()-i, i)) and scramble_string(a.substr(i, a.length()-i), b.substr(0, b.length()-i));
		bool cond2 = scramble_string(a.substr(0, i), b.substr(0, i)) and scramble_string(a.substr(i, a.length()-i), b.substr(i, b.length()-i));
		if(cond1 or cond2) return dp[a+b] = true;
	}
	return dp[a+b] = false;
}

int main() {
	string a, b;
	cin>>a>>b;
	if(!a.length() and !b.length()) cout<<"Strings Scrambled!"<<endl;
	else if(scramble_string(a, b) and a.length() == b.length()) cout<<"Strings Scrambled!"<<endl;
	else cout<<"Not Scrambled"<<endl;
	return 0;
}