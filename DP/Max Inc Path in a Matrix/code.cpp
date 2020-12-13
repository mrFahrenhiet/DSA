#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int lngIncUtil(vector<vector<int>> &mat,vector<vector<int>> &dp,int i,int j) {
    if(dp[i][j]>0) {
        return dp[i][j];
    }
    int up=1,dwn=1,lft=1,rgt=1;
    if(i+1<mat.size() and mat[i][j]<mat[i+1][j]) dwn = lngIncUtil(mat,dp,i+1,j)+1;
    if(i-1>=0 and mat[i][j]<mat[i-1][j]) up = lngIncUtil(mat,dp,i-1,j)+1;
    if(j-1>=0 and mat[i][j]<mat[i][j-1]) lft = lngIncUtil(mat,dp,i,j-1)+1;
    if(j+1<mat[0].size() and mat[i][j]<mat[i][j+1]) rgt = lngIncUtil(mat,dp,i,j+1)+1;
    return dp[i][j] = max(up,max(dwn,max(lft,rgt)));
} 
int longestIncreasingPath(vector<vector<int>>& mat) {
	if(mat.size()==0) {
		return 0;
	}
    vector<vector<int> > dp(mat.size()+1,vector<int>(mat[0].size()+1,0));
    int ans = 0;
    for(int i=0;i<mat.size();i++) {
        for(int j=0;j<mat[0].size();j++) {
            ans = max(ans,lngIncUtil(mat,dp,i,j));
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}
int main() {
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>m>>n;
	vector<vector<int> > v;
	for(int i=0;i<m;i++) {
		vector<int> temp;
		for(int j=0;j<n;j++) {
			int no;
			cin>>no;
			temp.push_back(no);
		}
		v.push_back(temp);
		temp.clear();
	}
	cout<<longestIncreasingPath(v);

return 0;}