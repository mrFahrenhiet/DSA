#include<bits/stdc++.h>
#define ll long long int
using namespace std;


bool is_possible(vector<vector<int> > board,int i,int j,int n,int num) {
	for(int x=0;x<n;x++) {
		if(board[x][j]==num || board[i][x]==num) {
			return false;
		}
	}
	int rootn = sqrt(n);
	int sub_row_s = (i/rootn)*rootn;
	int sub_row_e = (i/rootn)*rootn+rootn;
	int sub_col_s = (j/rootn)*rootn;
	int sub_col_e = (j/rootn)*rootn+rootn; 
	for(int l=sub_row_s;l<sub_row_e;l++) {
		for(int m=sub_col_s;m<sub_col_e;m++) {
			if(board[l][m]==num) {
				return false;
			}
		}
	}
	return true;
}


bool solve(vector<vector<int> > board,int i,int j,int n) {
	if(i>=n) {
		for(int row=0;row<n;row++) {
			cout<<endl;
			for(int col=0;col<n;col++) {
				cout<<board[row][col]<<" ";
			}
		}
		cout<<endl;
		return true;
	}
	if(j>=n) {
		return solve(board,i+1,0,n);
	}
	if(board[i][j]!=0) {
		return solve(board,i,j+1,n);
	}
	for(int k=1;k<=n;k++) {
		if(is_possible(board,i,j,n,k)) {
			board[i][j] = k;
			bool next_move = solve(board,i,j+1,n);
			if(next_move) {
				return true;
			}
		}
	}
	//backtrack
	board[i][j] = 0;
	return false;
}


int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<vector<int> > b(n);
    for(int row=0;row<n;row++) {
    	b[row] = vector<int>(n);
    	for(int col=0;col<n;col++) {
    		cin>>b[row][col];
    	}
    }
    bool ans = solve(b,0,0,n);
    return 0;

}