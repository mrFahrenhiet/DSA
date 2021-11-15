#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct Edges {
	int d;
	int w;
	Edges(): d(0), w(0) {}
	Edges(int dest, int weight): d(dest), w(weight) {}
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool in_bounds(vector<vector<int>>& earth, int r, int c) {
	return (r < earth.size() and r >=0) and (c < earth[0].size() and c >= 0);
}

void dfs(vector<vector<int>>& earth, vector<vector<bool>>& visited, int r, int c) {
	visited[r][c] = true;
	for(int i=0;i<4;i++) {
		if(in_bounds(earth, r+dx[i], c+dy[i]) and !visited[r+dx[i]][c+dy[i]] and !earth[r+dx[i]][c+dy[i]])
			dfs(earth, visited, r+dx[i], c+dy[i]);
	}
	return;
}
int nos_islands(vector<vector<int>>& earth) {
	vector<vector<bool>> visited(earth.size(), vector<bool>(earth[0].size(), false));
	int res = 0;
	for(int i=0;i<earth.size();i++) {
		for(int j=0;j<earth[0].size();j++) {
			if(!visited[i][j] and earth[i][j]==0) {
				res++;
				dfs(earth, visited, i, j);
			}
		}
	}
	return res;
}

int main() {
	int m, n;
	cin>>m>>n;
	vector<vector<int>> earth(m, vector<int>(n, 1));
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			int nos;
			cin>>nos;
			earth[i][j] = nos;
		}
	}
	int x = nos_islands(earth);
	cout<<x<<endl;
	return 0;
}