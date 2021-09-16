#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[1000][1000];
string lcs_print(string s1, string s2) {
	int m = s2.length(), n = s1.length();
	for(int i=1; i<=s1.length();i++) {
		for(int j=1;j<=s2.length();j++) {
			if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string res = "";
	while(n > 0 and m > 0) {
		if(s1[n-1]==s2[m-1]) {
			res.push_back(s1[n-1]);
			n--;
			m--;
		}
		else {
			if(dp[n][m] == dp[n-1][m]) n--;
			else if(dp[n][m]==dp[n][m-1]) m--;
		}
	}
	return res;
}

int main() {
	string s1, s2;
	cin>>s1>>s2;
	memset(dp, 0, sizeof(dp));
	string res = lcs_print(s1, s2);
	reverse(res.begin(), res.end());
	cout<<res<<endl;
	return 0;
}