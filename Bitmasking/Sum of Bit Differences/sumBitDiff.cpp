#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int sumBitDiff(vector<int> &arr) {
	int n = arr.size();
	int sumOfBits = 0;
	for(int i=0;i<32;i++) {
		int offCnt = 0;
		for(int j=0;j<arr.size();j++) {
			if((arr[j]&(1<<i))==0) offCnt++;
		}
		sumOfBits += offCnt*(n-offCnt);
	}
	return sumOfBits;
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
    vector<int> v;
    for(int i=0;i<n;i++) {
    	int no;
    	cin>>no;
    	v.push_back(no);
    }
    int res = sumBitDiff(v);
    cout<<res<<endl;
    return 0;

}