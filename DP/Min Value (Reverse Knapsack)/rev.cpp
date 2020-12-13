#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int dp[1005][1005];
int min_val(vector<int> &value, int n, int s,int i) {
	if(s==0) {
        return 0;
    }
    if(i==n) {
        return 100000;
    }
    if(dp[i][s]!=-1) {
        return dp[i][s];
    }
    int incs= 100000, ex=-1;
    if(i+1<=s && value[i]!=-1) {
        incs = min_val(value,n,s-i-1,i)+value[i];
    }
    ex = min_val(value,n,s,i+1);
    return dp[i][s] = min(incs,ex);
} 
int main() {
    int n,s;
    cin>>n>>s;
    vector<int> value;
    memset(dp,-1,sizeof dp);
    n=s;
    for(int i=0;i<n;i++) {
    	int no;
    	cin>>no;
    	value.push_back(no);
    }
	
    int ans = min_val(value,n,s,0);
	if(ans==100000) {
		cout<<-1<<endl;
	}
	else {
		cout<<ans<<endl;
	}
    return 0;

}