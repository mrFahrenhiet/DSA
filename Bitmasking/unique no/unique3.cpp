#include<iostream>
#include<vector>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,no,j,p=1,a=0;
    vector<int> s(5,0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>no;
        j =0;
        while(no>0) {
            int l = no & 1;
            s[j]+=l;
            no = no>>1;
            j++;
        }
    }

    for(int i=0;i<=j;i++) {
        s[i] = s[i]%3;
        a += p*s[i];
        p*=2;
    }
    cout<<a;
    return 0;

}