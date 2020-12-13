#include<iostream>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int n,a[100],l[100],r[100],maxl,maxr;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        maxl = a[i];
        for(int j=i;j>=0;j--) {
            if(maxl<=a[j]) {
                maxl = a[j];
                l[i] = maxl;
            }
        }
        // cout<<l[i]<<endl;
        maxr = a[i];
        for(int k=i;k<n;k++) {
            if(maxr<=a[k]) {
                maxr = a[k];
                r[i] = maxr;
            }
        }
        // cout<<r[i]<<",";
    }
    int units = 0;
    for(int i=0;i<n;i++) {
        units += min(l[i],r[i]) - a[i];
    }
    cout<<units;
	return 0;

}