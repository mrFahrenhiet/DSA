#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };


bool is_safe(vector<vector<int>>& board, int x, int y) {
	return x >= 0 && x < board.size() && y >= 0 && y < board.size() && board[x][y]==-1;
}



void display_board(vector<vector<int>>& board) {
	 for(int r=0;r<board.size();r++) {
		for(int c=0;c<board.size();c++) {
			cout<<board[r][c]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return;
}

void knights_tour(vector<vector<int>>& board, int i, int j, int m) {
	if(!is_safe(board, i, j)) return false; 
	if(m == board.size()*board.size()) {
		board[i][j] = m;
		display_board(board);
		board[i][j] = -1;
		return true;
	}
	board[i][j] = m;
	for(int k=0;k<8;k++) {
        int ni = i+dx[k], nj = j+dy[k];
		bool _ = knights_tour(board, ni, nj, m+1);
	}
    board[i][j] = -1;
	return false;
}

int main() {
	int n;
	cin>>n;
	vector<vector<int>> board(n, vector<int>(n, -1));
	bool res = knights_tour(board, 0, 0, 1);
	return 0;
}