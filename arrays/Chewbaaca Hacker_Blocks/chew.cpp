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
    char a[60];
    cin>>a;
    int i=0;
    if(a[0]=='9') {
    	i++;
    }
    for(;a[i]!='\0';i++) {
    	int digit = a[i] - '0';
    	if(digit>=5) {
    		digit = 9-digit;
    		a[i] = digit + '0'; 
    	}
    }
    cout<<a<<endl;
	return 0;

}