#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin>>s;
    int ans = 0;

    for(int i=0;i<s.length();i++) {
    	int j = s.substr(i).find("bear");
    	if(j!=-1)
    		ans += s.length() - (i+j+3);
    }
    cout<<ans<<endl;
    return 0;

}