#include<iostream>
#include<cmath>
using namespace std;

double sq_rt(int no,int pre) {
	double s=0,e=no;
	double m;
	double ans;
	//Integer part
	while(s<=e) {
		m = (s+e)/2;
		if(m*m==no) {
			ans = m;
			break;
		}
		else if(m*m>no) {
			e=m-1;
		}
		else {
			s=m+1;
			ans = m;
		}
	}
	// fractional
	float inc = 0.1; 
	for(int i=0;i<pre;i++) {
		while(ans*ans<=no) {
			ans+=inc;
		}
		ans-=inc;
		inc = inc/10;
	}
	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	long long int n,p;
	cin>>n>>p;
	cout<<sq_rt(n,p);

	return 0;
}