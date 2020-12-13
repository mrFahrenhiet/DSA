#include<iostream>
#include<string.h>
using namespace std;
void filter_char(char a[],int n) {
    int j= 0;
    while(n>0) {
        int l = n&1;
        if(l==1) {
            cout<<a[j];
        }
        j++;
        n=n>>1;
    }
}
void print_subset(char a[]) {
    int count=0;
    int n = strlen(a);
    for(int i=0;i<(1<<n);i++) {
        filter_char(a,i);
        count++;
        cout<<" ";
    }
    cout<<"\n"<<count<<"\n";
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    char a[20];
    cin>>a;
    print_subset(a);
    return 0;

}