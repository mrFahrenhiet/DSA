#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Helper {
public:
    int x,y,d,k;
    Helper(int xx,int yy,int dd,int kk) {
        this->x = xx;
        this->y = yy;
        this->d = dd;
        this->k = kk;
    }
};
bool isValid(int x, int y, int m, int n) {
    if((x<0 or x>=m) or (y<0 or y>=n)) 
        return false; 
  
    return true;
}
int shortestPath(vector<vector<int>>& grid, int k) {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int m = grid[0].size(), n = grid.size();
    queue<Helper> q;
    map<pair<int,int>,bool> visited;
    Helper node(0,0,0,k);
    q.push(node);
    int ans = INT_MAX;
   visited[make_pair(node.x,node.y)] = true;
    while(!q.empty()) {
        Helper t = q.front();
        q.pop();
        if(t.x==m-1 and t.y==n-1) {
        	//cout<<t.d<<endl;
            ans = min(ans,t.d);
        }
        for(int i=0;i<4;i++) {
            if(isValid(t.x+dx[i],t.y+dy[i],m,n) and !visited[make_pair(t.x+dx[i],t.y+dy[i])]) {
            	visited[make_pair(t.x+dx[i],t.y+dy[i])] = true;
                if(grid[t.y+dy[i]][t.x+dx[i]]==1 and t.k>0) {
                    Helper nw(t.x+dx[i],t.y+dy[i],t.d+1,t.k-1);
                    q.push(nw);
                    //cout<<nw.x<<" "<<nw.y<<" "<<nw.d<<" "<<nw.k<<endl;
                }
                else {
                    Helper nt(t.x+dx[i],t.y+dy[i],t.d+1,t.k);
                    q.push(nt);
                    //cout<<nt.x<<" "<<nt.y<<" "<<nt.d<<" "<<nt.k<<endl;
                }
            }
            
        }
    }
    if(ans==INT_MAX)
    	return -1;
    else
    	return ans;
}
int main() {
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	int m,n;
	cin>>m>>n;
	vector<vector<int>> grid(n,vector<int>(n,0));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			int p;
			cin>>p;
			grid[i][j] = p;
		}
	}
	int k;
	cin>>k;
	cout<<shortestPath(grid, k);
	return 0;
}