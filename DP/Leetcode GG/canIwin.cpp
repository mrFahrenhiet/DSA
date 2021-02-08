#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool canIwinUtil(int maxNos, int target, int k, int dp[]) {
    if(target<=0) return false;
    if(!dp[k]) return dp[k];
    for(int i=0;i<maxNos;i++) {
        if(!(k&1<<i) and !canIwinUtil(maxNos, target - i - 1, (k|1<<i), dp)) return dp[k] = true;
    }
    dp[k] = -1;
    return false;
}
bool canIwin(int maxNos, int target) {
    int sum = maxNos*(maxNos+1)/2;
    if(sum<target) return false;
    if(maxNos>=target) return true;
    if(sum==target) return maxNos%2;
    int dp[1<<15] = {};
    return canIwinUtil(maxNos, target, 0, dp); 
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int m,t;
    cin>>m>>t;
    if(canIwin(m,t)) cout<<"YES!"<<endl;
    else cout<<"NO!"<<endl;
    return 0;

}