#include <iostream>
#include <vector>
using namespace std;

//top down (TC = O(n*k) )
vector<int> v(1005,0);
int funct(int n,int k) {
    if(n==0) {
        return 1;
    }
    if(v[n]!=0) {
        return v[n];
    }
    int ans=0;
    for(int i=1;i<=k;i++) {
        if(n-i>=0)
            ans +=  funct(n-i,k);
    }
    return v[n] = ans;
}
//bottom up (TC = O(n*k) )
int functB(int n,int k) {
    vector<int> dp(n+5,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            if(i-j>=0)
                dp[i] += dp[i-j];
        }   
    }
    return dp[n];
}
//bottom up optimaized (TC = O(n+k) )
int functBotOpt(int n,int k) {
    vector<int> dp(n+5,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=k;i++) {
        dp[i] = 2*dp[i-1];
    }
    for(int i=k;i<=n;i++) {
        dp[i] = 2*dp[i-1] - dp[i-k-1];   
    }
    return dp[n];
}

int main() {
    int n,k;
    cin>>n>>k;
    cout<<functBotOpt(n,k);
}
