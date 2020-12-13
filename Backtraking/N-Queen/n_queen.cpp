#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int count=0;
bool is_safe(vector<vector<ll>> &v, ll n, ll i, ll j) {
    for(int r=0;r<i;r++) {
        if(v[r][j]==1) {
            return false;
        }
    }
    int x = i;
    int y = j;
    while(x>=0 && y>=0) {
        if(v[x][y]==1) {
            return false;
        }
        x--;
        y--;
    }
    x = i;
    y = j;
    while(x>=0 && y<n) {
        if(v[x][y]==1) {
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool n_queen(vector<vector<ll>> &v,ll n, ll i) {
    if(i>=n) {
        for(int row=0;row<n;row++) {
         for(int col=0;col<n;col++) {
             if(v[row][col]==1) {
                 cout<<"Q ";
             }
             else {
                 cout<<"_ ";
             }
                
         }
         cout<<endl; 
        }
        cout<<endl;
        count++;
        return true;
    }
    for(int j=0;j<n;j++) {
        if(is_safe(v,n,i,j)) {
            v[i][j] = 1;
            bool nextq = n_queen(v,n,i+1);
            v[i][j] = 0;
            // if(nextq) {
            //  return true;
            // }
        }
    }
    return false;
}
int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    vector<vector<ll>> q(n, vector<ll> (n,0));
    bool is_possible = n_queen(q,n,0);
    cout<<count;
    return 0;

}