#include<iostream>
#include<cmath>
using namespace std;
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
    int n,x,p,q,r,v,m,row,col;
    int y;
    cin>>n>>m;
    int **a = new int*[n];
    for(int i=0;i<n;i++) {
        a[i] = new int[m];

    }
    int **b = new int*[n];
    for(int i=0;i<n;i++) {
        b[i] = new int[m];

    }
    for(int li=0;li<n;li++) {
        for(int lj=0;lj<m;lj++) {
            cin>>a[li][lj];
        }
    }
    b[0][0] = a[0][0];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0) {
                b[i][j] = a[i][j-1]+a[i][j];
            }
            if(j==0) {
                b[i][j] = a[i-1][j]+a[i][j];
            }
            else {
                b[i][j] = a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            }
        }
    }
    
    for(int li=n-1;li>=0;li--) {
        for(int lj=m-1;lj>=0;lj--) {
            if(li==n-1) {
                continue;
            }
            b[li][lj]+=b[li+1][lj];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    // int max =0;
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         if(max<b[i][j]) {
    //             max = b[i][j];
    //             row = i;
    //             col = j;
    //         }
    //     }
    // }
    // cout<<max<<"="<<"TL-"<<row<<","<<col<<" "<<"BR-"<<n-1<<","<<m-1<<"\n";
    return 0;
}