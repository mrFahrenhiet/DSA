#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int tcase;
    cin>>tcase;
    for(int t=0;t<tcase;t++) {
        ll n,ans=0,sum=0;
        cin>>n;
        vector<ll> v;
        vector<ll> freq(n,0);
        freq[0]=1;
        for(int i=0;i<n;i++) {
            ll no;
            cin>>no;
            sum+=no;
            sum%=n;
            sum=(sum+n)%n;
            freq[sum]++;
        }
        for(int i=0;i<n;i++) {
            ll m = freq[i];
            ans+=m*(m-1)/2;      
        }
        cout<<ans<<endl;
    }

    return 0;

}