#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[1000][1000];
int scs_len(string s1, string s2) {
	for(int i=0;i<=s1.length();i++) {
		for(int j=0;j<=s2.length();j++) {
			if(i==0 or j==0) dp[i][j] = 0;
			else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return s1.length() + s2.length() - dp[s1.length()][s2.length()];
}

string scs(string s1, string s2) {
	string res = "";
	for(int i=0;i<=s1.length();i++) {
		for(int j=0;j<=s2.length();j++) {
			if(i==0 or j==0) dp[i][j] = 0;
			else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int n = s1.length(), m = s2.length();
	while(n and m) {
		if(s1[n-1]==s2[m-1]) {
			res.push_back(s1[n-1]);
			n--;
			m--;
		}
		else if(dp[n-1][m] > dp[n][m-1]) {
			res.push_back(s1[n-1]);
			n--;
		}
		else {
			res.push_back(s2[m-1]);
			m--;
		}
	}

	while(n) {
		res.push_back(s1[n-1]);
		n--;
	}

	while(m) {
		res.push_back(s2[m-1]);
		m--;
	}

	return res;
}
int main() {
	memset(dp, 0, sizeof(dp));
	string s1, s2;
	cin>>s1>>s2;
	int x = scs_len(s1, s2);
	cout<<x<<endl;
	string common_super_seq = scs(s1, s2);
	cout<<common_super_seq<<endl;
	return 0;
}