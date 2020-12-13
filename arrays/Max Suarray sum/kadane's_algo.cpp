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
        s+=a[i];
        if(s<0) {
            s=0;
        }
        if(max<s) {
            max = s;
            ii = i;
        }
    		// cout<<endl;
    }
    cout<<endl;
    cout<<"Sum:"<<max<<endl;
	return 0;
}