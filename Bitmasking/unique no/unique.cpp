#include<iostream>
using namespace std;
#define l long int

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    l n;
    cin>>n;
    l no,ans=0;
    for(int i=0;i<n;i++) {
        cin>>no;
        ans = ans^no;
    }
    cout<<ans<<endl;
	return 0;

}