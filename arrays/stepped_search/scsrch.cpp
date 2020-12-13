#include<iostream>


/*Staircase Search

    TC =  O(n)
    condtion: Only for sorted array (from both row and col)
*/


using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int n,a[50][50],i,j,src;
    cin>>n;
    i=0;j=n-1;
    for(int k=0;k<n;k++) {
        for(int l=0;l<n;l++) {
            cin>>a[k][l];
        }
    }
    bool flag =false;
    cin>>src;
    while(flag!=true||i<n||j>0) {
        if(src>a[i][j]) {
            i++;
        }
        else if(src<a[i][j]) {
            j--;
        }
        else {
            flag = true;
            break;
        }
    }
    cout<<i<<" "<<j;
	return 0;
}