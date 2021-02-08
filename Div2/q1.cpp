#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool canReach(string s, int px, int py) {
    unordered_map<char, int> comFreq;
    for(auto c: s) comFreq[c]++;
    // if((px<0 and !comFreq.count('L')) or (px>0 and !comFreq.count('R'))) return false;
    // if((py<0 and !comFreq.count('D')) or (py>0 and !comFreq.count('U'))) return false;
    if((px>0 and px>comFreq['R']) or (py>0 and py>comFreq['U'])) return false;
    if((py<0 and -1*py>comFreq['D']) or (px<0 and -1*px>comFreq['L'])) return false;
    return true;
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
    while(t--) {
        int px, py;
        cin>>px>>py;
        string s;
        cin>>s;
        if(canReach(s, px, py)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;

}