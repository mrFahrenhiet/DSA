#include<bits/stdc++.h>
using namespace std;
int p = 1,ans=0;
int cvt_int(string &c,int i,int e) {
    if(c[i]=='\0') {
        return ans;
    }
    int d = c[i]-'0';
    return d*pow(10,e)+cvt_int(c,i+1,e-1);

}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string n;
    cin>>n;
    int e = n.length()-1;
    int m = cvt_int(n,0,e);
    cout<<m<<endl;

    return 0;

}