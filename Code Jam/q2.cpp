#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Solution {
public:
    int minCost(string s, int x, int y) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i]=='?') {
                if(i==0) {
                    int j = i;
                    while(s[j]=='?') j++;
                    s[i] = s[j];
                }
                else if(i==s.length()-1) s[i] = s[i-1];
                else {
                    if(s[i+1]=='?') s[i] = s[i-1];
                    else if(s[i+1]==s[i-1]) s[i] = s[i-1];
                    else {
                        if(x>y) s[i] = 'J';
                        else s[i] = 'C';
                    }
                }
            }
        }
        int cost = 0;
        for(int i = 0; i < s.length()-1; i++) {
            if(s[i]!=s[i+1]) {
                if(s[i]=='C') cost += x;
                else cost += y;
            }
        }
        return cost;
    }
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t, idx = 0;
    cin>>t;
    while(t--) {
        idx++;
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        Solution sol;
        int r = sol.minCost(s, x, y);
        cout<<"Case #"<<idx<<": "<<r<<endl;
    }
    return 0;

}