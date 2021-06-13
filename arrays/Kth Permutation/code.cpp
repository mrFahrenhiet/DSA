#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
private:
    ll factorial(ll x) {
        if(x==0) return 1;
        ll res = 1;
        while(x) {
            res *= x;
            x--;
        }
        return res;
    }
public:
    string kthPermutation(ll n, ll k) {
        string res = "";
        bool visited[n+1];
        memset(visited, false, sizeof(visited));
        int x = n;
        while(n and k>=0) {
            ll f = this->factorial(n-1);
            for(int i=1;i<=x;i++) {
                if(i*f>=k and !visited[i]) {
                    visited[i] = true;
                    res.push_back(i+'0');
                    k -= (i-1)*f;
                    break;
                }
            }
            n--;
        }
        return res;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ll t,n,k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        Solution sol;
        cout<<sol.kthPermutation(n, k)<<endl;
    }
    return 0;

}