#include<iostream>
#include<cmath>
using namespace std;
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
        int *rev = new int[n];

        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++) {
            rev[i]=0;
        }
        
        for(int i=0;i<n;i++) {
            int k=0;
            int b = arr[i];
            while(b>0){
                int r = b%10;
                k++;
                b=b/10;
            }
            int l = k;
            b = arr[i];
            while(b>0){
                int r = b%10;
                rev[i] += r*pow(10,l-1);
                l--;
                b=b/10;
            }
        }
        for(int i=0;i<n;i++) {
            cout<<rev[i]<<endl;
        }
    }

	return 0;

}