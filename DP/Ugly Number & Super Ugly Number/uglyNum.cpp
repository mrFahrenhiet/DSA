#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> sieve(1,1);
        int div2 = 0, div3 = 0, div5 = 0;
        for(int i=1;i<n;i++) {
            sieve.push_back(min(sieve[div2]*2, min(sieve[div3]*3, sieve[div5]*5)));
            if(sieve.back()==sieve[div5]*5) div5++;
            if(sieve.back()==sieve[div3]*3) div3++;
            if(sieve.back()==sieve[div2]*2) div2++;
        }
        return sieve.back();
    }
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
	cin>>t;
	while(t--) {
    	ll n;
    	cin>>n;
    	Solution sol
    	cout<<sol.nthUglyNumber(n)<<endl;
	}
    return 0;

}