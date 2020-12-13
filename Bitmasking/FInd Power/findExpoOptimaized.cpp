#include<iostream>
using namespace std;
int main() {
	int n,p;
	cin>>n>>p;
	int ans = 1;
	int t = p;
	int a = n;
	while(t>0) {
		int l = t & 1;
		if(l==1) {
			ans*= a;
		}
		t=t>>1;
		a = a*a;
	}
	cout<<ans;
	return 0;
}