#include<bits/stdc++.h>
using namespace std;

void print_mat(int n,string inc,string out) {
	vector<vector<char> > matrix(50,vector<char>(50,'N'));
	for(int row=0;row<n;row++) {
		matrix[row][row] = 'Y';
	}
	for(int i=0;i<n;i++) {
		for(int j=i-1;j>=0;j--) {
			if(inc[i-1]=='N') {
				break;
			}
			if(matrix[i][j+1]=='N') {
				break;
			}
			else if(out[j+1]=='Y' && inc[j]=='Y') {
				matrix[i][j] = 'Y';
			}
			else {
				matrix[i][j] = 'N';
			}
		}
		for(int j=i+1;j<n;j++) {
			if(out[i]=='N') {
				break;
			}
			if(matrix[i][j-1]=='N') {
				break;
			}
			else if(out[j-1]=='Y' && inc[j]=='Y') {
				matrix[i][j] = 'Y';
			}
			else {
				matrix[i][j] = 'N';
			}
		}
	}
	for(int row=0;row<n;row++) {
		for(int col=0;col<n;col++) {
			cout<<matrix[row][col];
		}
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
    int T;
    cin>>T;
    int num = 1;
    while(T--) {
    	int N;
    	cin>>N;
    	string I;
    	cin>>I;
    	string O;
    	cin>>O;
    	cout<<"Case #"<<num<<":"<<endl;
    	print_mat(N,I,O);
    	// cout<<endl;
    	num++;
    }
    return 0;

}