#include<iostream>
#include<vector>
#include<bitset>
#define ll long long int
using namespace std;
int count=0;
bitset<30> column,d1,d2;

bool n_queen(vector<vector<ll>> &v,ll n, ll i) {
    if(i>=n) {
        count++;
        return true;
    }
    for(int j=0;j<n;j++) {
        if(!column[j] && !d1[i-j+n-1] && !d2[i+j]) {
            column[j] = d1[i-j+n-1] = d2[i+j] = 1;
            v[i][j] = 1;
            bool nextq = n_queen(v,n,i+1);
            v[i][j] = 0;
            column[j] = d1[i-j+n-1] = d2[i+j] = 0;
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