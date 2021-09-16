#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> convert_a_to_b(string a, string b) {
	// LCS DP
	int dp[a.length()+1][b.length()+1];
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<=a.length();i++) {
		for(int j=0;j<=b.length();j++) {
			if(i==0 or j==0) dp[i][j] = 0;
			else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int instetion = b.length() - dp[a.length()][b.length()];
	int deletion = a.length() - dp[a.length()][b.length()];
	return {instetion, deletion};
}

int main() {
	string a, b;
	cin>>a>>b;
	vector<int> res_inset_del = convert_a_to_b(a, b);
	cout<<res_inset_del[0]<<" "<<res_inset_del[1]<<endl;\
	return 0;
}