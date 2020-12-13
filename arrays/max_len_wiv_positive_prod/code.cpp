#include<bits/stdc++.h>
using namespace std;
int maxLenSubarray(vector<int> &v) {
	int maxCount = 0;
	int i = 0;
	int n = v.size();
	while(i<n) {
		int s = i;
		while(v[s]==0 and s<n) s++;
		int e = i;
		int fneg = -1;
		int lneg = -1;
		int negC = 0;
		while(v[e]!=0 and e<n) {
			if(v[e]<0) {
				negC++;
				if(fneg==-1) fneg = e;
				lneg = e;
			}
			e++;
		}
		if(negC%2==0) maxCount = max(maxCount,abs(s-e));
		else {
			if(fneg!=-1) max(maxCount,e-fneg-1);
			if(lneg!=-1) max(maxCount,lneg-s);
		}
		i = e+1;
	}
	return maxCount;
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
	cout<<maxLenSubarray(v)<<endl;
	return 0;
}