#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int helper(int l, int s)
{
    int count  = s - 1 ; 
    return count ; 
}
int findNosL(int grid[1001][1001], int r, int c) {
    int gDown[r][c] = {0}, gUp[r][c] = {0}, gLeft[r][c] = {0}, gRight[r][c] = {0};
    for(int i = 0; i < r;  i++) {
        for(int j = 0; j < c; j++) {
            if(!i) gUp[i][j] = grid[i][j];
            else {
                if(grid[i][j]==1) gUp[i][j] = gUp[i-1][j] + grid[i][j];
                else gUp[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < r;  i++) {
        for(int j = 0; j < c; j++) {
            if(j==0) gRight[i][j] = grid[i][j];
            else {
                if(grid[i][j]==1) gRight[i][j] = gRight[i][j-1] + grid[i][j];
                else gRight[i][j] = 0;
            }
        }
    }
    for(int i = r-1; i>=0; i--) {
        for(int j = c-1; j>=0;j--) {
            if(i==r-1) gDown[i][j] = grid[i][j];
            else {
                if(grid[i][j]==1) gDown[i][j] = gDown[i+1][j] + grid[i][j];
                else gDown[i][j] = 0;
            }
        }
    }
    for(int i = r-1; i>=0; i--) {
        for(int j = c-1; j>=0;j--) {
            if(j==c-1) gLeft[i][j] = grid[i][j];
            else {
                if(grid[i][j]==1) gLeft[i][j] = gLeft[i][j+1] + grid[i][j];
                else gLeft[i][j] = 0;
            }
        }
    }
    int x = 0;
    for(int i=0;i<r;i++) {

        for(int j=0;j<c;j++) {
            int u = gUp[i][j];
            int d = gDown[i][j];
            int r = gRight[i][j];
            int l = gLeft[i][j];
            if(min(u,l)>1) {
                int mi = min(u,l); 
                int ma = max(u,l);
                if(mi*2>ma) {
                    x += (ma/2 - 1); 
                }
                else {
                    x+= mi - 1;
                }
                if(mi>= 4) {
                    x += (mi/2-1); 
                }
            }
            if(min(u,r) > 1)
            {
                int mi = min(u,r) ; 
                int ma = max(u,r) ;
                if(mi * 2 > ma)
                {
                    x+= helper(ma,ma/2) ; 
                } 
                else
                {
                    x+= helper(ma,mi) ; 
                }
                if(mi>= 4)
                {
                    x += helper(mi,mi/2) ; 
                }
            }
            if(min(d,r) > 1)
            {
                int mi = min(d,r) ; 
                int ma = max(d,r) ;
                if(mi * 2 > ma)
                {
                    x+= helper(ma,ma/2) ; 
                }
                else
                {
                    x+= helper(ma,mi) ; 
                } 
                if(mi>= 4)
                {
                    x += helper(mi,mi/2) ; 
                }
            }
            if(min(d,l) > 1)
            {
                int mi = min(d,l) ; 
                int ma = max(d,l) ;
                if(mi * 2 > ma)
                {
                   x+= helper(ma,ma/2) ; 
                } 
                else
                {
                    x+= helper(ma,mi) ; 
                }
                if(mi>= 4)
                {
                    x += helper(mi,mi/2) ; 
                }
            }
        }
    }
    return x;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t, i = 1;
    cin>>t;
    while(t--) {
        int r,c;
        cin>>r>>c;
        int grid[1001][1001] = {0};
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>grid[i][j];
            }
        }
        int nosL = findNosL(grid, r, c);
        cout<<"Case #"<<i<<": "<<nosL<<endl;
        i++;
    }
    return 0;

}