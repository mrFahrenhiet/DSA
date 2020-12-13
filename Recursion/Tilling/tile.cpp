#include<iostream>
#include<vector>
using namespace std;
vector<int> v(-1,10000);
int tile(int n,int m) {
    if(n<m) {
        return 1;
    }
    else if(n==m) {
        return 2;
    }
    if(v[n]!=-1) {
        return v[n];
    }
    int x = tile(n-1,m);
    int y = tile(n-m,m);
    return v[n] = x+y;
}
int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        int n,m;
        cin>>n>>m;
        int t = tile(n,m);
        cout<<t<<endl;
    }
    return 0;
}