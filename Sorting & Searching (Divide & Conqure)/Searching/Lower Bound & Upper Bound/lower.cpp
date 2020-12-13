#include<iostream>
#include<algorithm>

using namespace std;

int find_lower(int a[],int n,int key) {
	int s,e,ans;
	ans = -1;
	s=0; e=n-1;
	while(s<=e) {
		int m = (s+e)/2;
		if(a[m]==key) {
			ans = m; 
			e = m-1;
		}
		else if(a[m]>key) {
			e=m-1;
		}
		else {
			s=m+1;
		}
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
	int n,key,ans;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	cin>>key;
	sort(a,a+n);
	ans = find_lower(a,n,key);
	if(ans==-1) {
		cout<<"element not found!"<<endl;
	}
	else {
		cout<<ans<<endl;
	}
	return 0;
}