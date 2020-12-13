#include<iostream>
using namespace std;

int search(int a[],int s,int e, int key) {
	if(s>e) {
		return -1;
	}
	int m = (s+e)/2;
	if(a[m]==key) {
		return m;
	}
	//First line
	if(a[s]<=a[m]) {
		if(key>=a[s] && key<=a[m]) {
			return search(a,s,m-1,key);
		}
		else {
			return search(a,m+1,e,key);
		}
	}
	//Sec line
	if(key>=a[m] && key<=a[e]) {
		return search(a,m+1,e,key);
	}
	return search(a,s,m-1,key);
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	int a[] = {5,6,7,1,2,3,4};
	int key,s,e;
	s=0;
	e = 6;
	cin>>key;
	int pos = search(a,s,e,key);
	cout<<pos;
	return 0;
}