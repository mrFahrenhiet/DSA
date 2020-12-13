#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void dfs(int i, int j, vector<vector<char>>& board) {
    if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!='O') 
        return;
    board[i][j] = '$';
    dfs(i+1,j,board);
    dfs(i-1,j,board);
    dfs(i,j+1,board);
    dfs(i,j-1,board);
    return;
}
void capture(vector<vector<char>>& board,int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j]=='$') {
                board[i][j]='O';
            }
            else if(board[i][j]=='O') {
                board[i][j]='X';
            }
        }
    }
    return;
}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    if(n==0)
        return;
    int m = board[0].size();
    for(int i=0;i<n;i++) {
        if(board[i][0]=='O') {
            dfs(i,0,board);
        }
        if(board[i][m-1]=='O') {
            dfs(i,m-1,board);
        }
    }
    for(int j=0;j<m;j++) {
        if(board[0][j]=='O') {
            dfs(0,j,board);
        }
        if(board[n-1][j]=='O') {
            dfs(n-1,j,board);
        }
    }
    capture(board,n,m);
    return;
}
int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	int m,n;
	cin>>n>>m;
	vector<vector<char>> board(n,vector<char>(m,'~'));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			char ch;
			cin>>ch;
			board[i][j] = ch;
		}
	}
	solve(board);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}