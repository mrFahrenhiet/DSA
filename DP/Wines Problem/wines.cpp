#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > dp(100,(vector<int>(100,-1)));
int profit(vector<int> &v,int i,int j,int y) {
    if(i>j) {
        return 0;
    }
    if(dp[i][j]!=-1)
    int st = y*v[i] + profit(v,i+1,j,y+1);
    int en = y*v[j] + profit(v,i,j-1,y+1);
    int profit = dp[i][j] = max(st,en);
    return profit; 
}
int main() {
    int n;
    cin>>n;
    vector<int> wines;
    for(int i=0;i<n;i++) {
        int no;
        cin>>no;
        wines.push_back(no);
    }
    cout<<profit(wines,0,n-1,1);
}
