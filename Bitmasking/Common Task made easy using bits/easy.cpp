#include<iostream>
using namespace std;
#define l long int

int findi(int n,int i){
    int mask = 1<<i;
    return (n & mask)>0?1:0;
}

int setbit(int &n,int i) {
    int mask = 1<<i;
    int ans = (n|mask);
    return ans;
} 
int clearbit(int &n,int i) {
    int mask = ~(1<<i);
    int ans = n & mask;
    return ans;
}
int updatebit(int &n, int i,int v) {
    int mask = v<<i;
    int step = clearbit(n,i);
    int ans = step | mask;
    return ans;
}
int clear_range(int &n,int r) {
    int mask = -1<<r;
    return (mask & n);
}
int clear_range_ij(int n,int i,int j) {
    int a = (-1<<j+1);
    int b = (1<<i)-1;
    int mask = a | b;
    return (n&mask);
}
int replace_range(int n,int i,int j,int rep) {
    int s1 = clear_range_ij(n,i,j);
    int mask = rep<<i;
    return (n | mask);
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
    int i;
    cin>>i;
    cout<<replace_range(1024,2,6,21);
	return 0;

}