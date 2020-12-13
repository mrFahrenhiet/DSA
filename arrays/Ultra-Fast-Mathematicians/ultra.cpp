#include<iostream>
#include<string>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	for(int i=0;i<t;i++) {
		string s1,s2;
		cin>>s1>>s2;
		char *d1 = &s1[0];
		char *d2 = &s2[0];
		while(*d1!='\0' && *d2!='\0') {
			if(*d1!=*d2) {
				cout<<"1";
			}
			else {
				cout<<"0";
			}
			d1++;
			d2++;
		}
		cout<<endl;
	}
	return 0;
}
