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
    int n,m,x;
    x=0;
    cin>>n>>m;
    int **a = new int*[n];
    for(int i=0;i<n;i++) {
        a[i] = new int[m];

    }
    for(int li=0;li<n;li++) {
        for(int lj=0;lj<n;lj++) {
            cin>>a[li][lj];
        }
    }

    for(int li=0;li<n;li++) {
        for(int lj=0;lj<n;lj++) {
            for(int bi=li;bi<n;bi++) {
                for(int bj=lj;bj<n;bj++) {
                    // cout<<"\n";
                    // x=0;
                    for(int i=li;i<=bi;i++) {
                        for(int j=lj;j<=bj;j++) {
                            x+=a[i][j];
                            // cout<<a[i][j];
                        }
                        // cout<<"\n";
                    }
                    // cout<<x<<endl;
                }
            }
            
        }
    }
    cout<<x<<"\n";
	return 0;

}