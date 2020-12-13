#include<iostream>
#include<cmath>
using namespace std;

int biolen(int a[],int n) {
    bool flag = false;
    int li=1,lb=1,ld=1,l=1;
    for(int i=0;i<n;i++) {
        if(a[i]<a[i+1]) {
            lb=1;
            li++;
            flag = true;
        }
        else if(a[i]>a[i+1] && flag==true) {
            lb++;
        }
        if(a[i]>a[i+1]) {
            ld++;
        }
        l = max(l,max((li+lb),ld));
        if(a[i]>a[i+1] && flag==false) {
            li = 1;
            lb = 1;
        }
        else if(a[i]<a[i+1]) {
            ld = 1;
        }
    }
    l = max(l,max((li+lb),ld));
    return l;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int len = biolen(arr,n);
        cout<<len<<endl;
    }
	return 0;

}