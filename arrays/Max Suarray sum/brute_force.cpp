#include<iostream>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int a[1000],n,s,max,ii,jj;
    s=0;
    max=s;
    cin>>n;
    for(int i=0;i<n;i++) {
    	cin>>a[i];
    }
    for(int i=0;i<n;i++) {
    	for(int j=i;j<n;j++) {
    		s=0;
    		for(int k=i;k<=j;k++) {
    			s+=a[k];
    			if(max<s) {
    				max = s;
    				ii = i;
    				jj = j;
    			}
    		}
    		// cout<<endl;
    	}
    }
    cout<<"Sub-Array:";
    for(int l=ii;l<=jj;l++) {
    	cout<<a[l]<<" ";
    }
    cout<<endl;
    cout<<"Sum:"<<max<<endl;
	return 0;

}