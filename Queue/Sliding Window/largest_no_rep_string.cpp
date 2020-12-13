#include<bits/stdc++.h>
using namespace std;
int largest_non_rep_string(char a[]) {
	vector<int> v(256,-1);
	int curr_len = 1;
	int max_len = 1;
	int n = strlen(a);
	v[0] = 0;
	for(int i=1;i<n;i++) {
		int last_occ = v[a[i]];
		if(last_occ==-1 || last_occ<i-curr_len) {
			curr_len+=1;
			max_len = max(curr_len,max_len);
		}
		else {
			if(max_len<curr_len) {
				max_len=curr_len;
			}
			curr_len=i-last_occ;
		}
		v[a[i]] = i;
	}
	return max_len;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    char a[1000];
    cin>>a;
    int x = largest_non_rep_string(a);
    cout<<x<<endl;
    return 0;

}