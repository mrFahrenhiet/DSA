#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define max_int 1000001
#define ll long long int
void sieve_eratosthenes(vector<bool>&a) {
	for(ll i=2;i<a.size();i+=2) {
		a[i] = false;
	}
	for(ll i=3;i<sqrt(a.size());i++) {
		if(a[i]==true){
			for(ll j = i*i;j<a.size();j+=i) {
				a[j] = false;
			}
		}
	}
	a[0]=false;
	a[1]=false;
	a[2]=true;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    vector<bool> a(max_int,true);
    vector<int> b;
    sieve_eratosthenes(a);
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) {
    	if(a[i]==true) {
    		b.push_back(i);
    	}
    }
    for(auto it: b) {
    	cout<<it<<" ";
    }
    return 0;

}