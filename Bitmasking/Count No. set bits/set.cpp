#include<iostream>
#include<cmath>
using namespace std;

int app1(int n) {
    int c=0;
    while(n>0) {
        int l = n & 1;
        if(l==1) {
            c++;
        }
        n = n>>1;
    }
    return c;
}
int app2(int n) {
    int c=0;
    while(n>0) {
        n= n & (n-1);
        c++;
    }
    return c;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,c;
    cin>>n;
    c = app2(n);
    cout<<c<<endl;
    return 0;

}