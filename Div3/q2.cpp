#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool canMake(string x, string test, string target) {
    for(int i=0)
	return false;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    string target = "2020";
    string test = "";
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	string x;
    	cin>>x;
    	if(canMake(x, test, target)) cout<<"YES"<<endl;
    	else {
    		cout<<"NO"<<endl;
    	}
    	test = "";
    }
    return 0;

}