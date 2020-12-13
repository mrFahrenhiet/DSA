#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void dfs(vector<vector<bool>> &gridUp, int row, int col) {
	if(row>=gridUp.size() or col>=gridUp.size() or row<0 or col<0)
		return;
	
	if(gridUp[i][j])
		return;
	
	dfs(gridUp,i+1,j);
	dfs(gridUp,i-1,j);
	dfs(gridUp,i,j+1);
	dfs(gridUp,i,j-1);
	return;
}
int regionCuts(vector<string> &grid,int n) {
	vector<vector<bool>> gridUp(n*3,vector<bool>(n*3,false));
	int region = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(grid[i][j]='/') {
				gridUp[i*3+0][j*3+2] = true;
				gridUp[i*3+1][j*3+1] = true;
				gridUp[i*3+2][j*3+0] = true;
			}
			else if(grid[i][j]=='\\') {
				gridUp[i*3+0][j*3+0] = true;
				gridUp[i*3+1][j*3+1] = true;
				gridUp[i*3+2][j*3+2] = true;
			}
		}
	}
	for(int i=0;i<n*3;i++) {
		for(int j=0;j<n*3;j++) {
			if(!gridUp[i][j]) {
				dfs(gridUp,i,j);
				region++;
			}
		}
	}
	return region;
}

int main() {
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	/* Write main 
	input grid
	call function regionCuts
	*/
	return 0;
}