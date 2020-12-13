#include <iostream>
using namespace std;
bool maze_run(char maze[][100],int o[][100],int m,int n, int i,int j) {
    if(maze[i][j]=='X') {
        return false;
    }
    if(i==m && j==n) {
        o[m][n] =1;
        for(int r=0;r<=m;r++) {
            for(int c=0;c<=n;c++) {
                cout<<o[r][c]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(i>m || j>n) {
        return false;
    }
    o[i][j] = 1;
    bool right = maze_run(maze,o,m,n,i,j+1);
    if(right){
        return true;
    }
    bool down  = maze_run(maze,o,m,n,i+1,j);
    if(down){
        return true;
    }
    o[i][j] = 0;
    return false;

}
int main() {
    int m,n;
    cin>>m>>n;
    char a[100][100];
    int o[100][100] = {0};
    for(int r=0;r<m;r++) {
        for(int c=0;c<n;c++) {
            cin>>a[r][c];
        }
    }
    if(!maze_run(a,o,m-1,n-1,0,0)) {
        cout<<-1;
    } 
}
