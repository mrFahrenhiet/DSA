#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void printMat(char mat[100][100],int R,int C) {
	for(int i=0;i<R;i++) {
		cout<<endl;
		for(int j=0;j<C;j++) {
			cout<<mat[i][j];
		}
	}
}
void floodFill(char mat[][100],int R,int C,int i,int j,char ch,char color) {
	//base case
	if(i>=R or j>=C or i<=0 or j<=0) {
		return;
	}
	if(mat[i][j]!=ch) {
		return;
	}
	if(mat[i][j]==color) {
		return;
	}

	mat[i][j] = color;
	//recursive condn
	floodFill(mat,R,C,i+1,j,ch,color); //East
	floodFill(mat,R,C,i-1,j,ch,color); //West
	floodFill(mat,R,C,i,j+1,ch,color); //North
	floodFill(mat,R,C,i,j-1,ch,color); //South
	return;

}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int R,C;
    cin>>R>>C;
    char canvas[100][100];
    for(int i=0;i<R;i++) {
    	for(int j=0;j<C;j++) {
    		cin>>canvas[i][j];
    	}
    }
    printMat(canvas,R,C);
    cout<<endl;
    floodFill(canvas,R,C,3,1,'3','r');
    printMat(canvas,R,C);
    return 0;

}