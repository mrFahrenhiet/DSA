#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node {
	int i,j,dist;
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool isValid(int i,int j,int m,int n) {
	if ((i<0 or i>m-1) or (j<0 or j>n-1)) 
        return false; 
  
    return true;
}

bool isSafe(int i,int j, char mat[][100],int op[][100]) {
	if(mat[i][j]!='O' or op[i][j]!=-1) {
		return false;
	}
	return true;
}

void shortest_dist(char mat[][100],int m,int n) {
	int op[100][100];
	queue<node> q;
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			op[i][j] = -1;
			if(mat[i][j]=='G') {
				node l = {i,j,0};
				q.push(l);
				op[i][j] = 0;
			}
		}
	}
	while(!q.empty()) {
		node temp = q.front();
		int x = temp.i, y = temp.j, dist = temp.dist;
		//cout<<x<<" "<<y<<" "<<dist<<endl;
		for(int k=0;k<4;k++) {
			if(isSafe(x+dx[k],y+dy[k],mat,op) and isValid(x+dx[k],y+dy[k],m,n)) {
				// cout<<dist+1<<endl;
				op[x+dx[k]][y+dy[k]] = dist+1;
				node neighbour = {x+dx[k],y+dy[k],dist+1};
				q.push(neighbour);
			}
		}
		q.pop();
	}
	for (int i=0;i<m;i++) { 
        for (int j=0; j<n;j++) 
            cout<<op[i][j]<<" "; 
        cout<<endl; 
    } 

}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    char mat[100][100];
    for(int i=0;i<n;i++) {
    	for(int j=0;j<n;j++) {
    		cin>>mat[i][j];
    	}
    }
    shortest_dist(mat,m,n);

    return 0;

}