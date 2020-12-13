#include<iostream>
#include<string>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int m,n,k,s; //row col str_req str_given
    cin>>n>>m>>k>>s;
    char a[100][100];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    if(s>=k) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(a[i][j]=='#') {  
                  break;
                }
                else if(a[i][j]=='.') {
                    if(j==m-1) {
                        s=s-2;
                    }
                    else {
                        s=s-3;
                    }
                }
                else if(a[i][j]=='*') { 
                    if(j==m-1) {
                        s+=5;
                    }
                    else {
                        s=s+4;
                    }
                }
            }
        }
        cout<<"Yes"<<endl<<s<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
	return 0;

}