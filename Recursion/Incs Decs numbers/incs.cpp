#include<iostream>
#include<vector>
using namespace std;
void decs(int n) {
    if(n==0) {
        cout<<0<<" ";
        return;
    }
    cout<<n<<" ";
    decs(n-1);
}
void incs(int n) {
    if(n==0) {
        cout<<0<<" ";
        return;
    }
    incs(n-1);
    cout<<n<<" ";
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    incs(n);
    decs(n);
    return 0;

}