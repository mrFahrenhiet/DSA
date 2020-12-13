#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,sum;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        cout<<a[i]<<endl;
    }
    cout<<"\n";
    int target;
    cin>>target;
    int *l = &a[0];
    int *r = &a[n-1];
    while(l<r) {
        sum = *l+*r;
        if(sum<target) {
            l+=1;
        }
        else if(sum>target) {
            r-=1;
        }
        else {
           cout<<*l<<" and "<<*r<<"\n";
           l+=1; 
        }

    }
    // for(int i=0;i<n;i++) {
    //     for(int j=i;j<n;j++) {
    //         sum = a[i] + a[j];
    //         if(sum==target) {
    //             cout<<a[i]<<" and "<<a[j]<<"\n";
    //         }
    //     }
    // }
    return 0;
}