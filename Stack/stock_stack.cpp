#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#define ll long long int
using namespace std;
int getMaxSpan(vector<int> &v) {
	stack<int> s;
	int ans=1;
	vector<int> span;
	for(int i=0;i<v.size();i++) {
		if(s.empty()) {
			s.push(i);
			ans = max(ans,i+1);
		}
		else if(v[s.top()]>=v[i]) {
			ans = max(ans,(i-s.top()+1));
			s.push(i);
		}
		else {
			while(v[s.top()]<v[i] && !s.empty()) {
				s.pop();
			}
			if(s.empty()) {
				ans = max(ans,i+1);
				s.push(i);
			}
			else if(v[s.top()]>=v[i]) {
				ans = max(ans,(i-s.top()));
				s.push(i);
			}
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
    int t;
    cin>>t;
    vector<int> v;
    while(t--) {
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++) {
    		int no;
    		cin>>no;
    		v.push_back(no);
    	}
    	cout<<getMaxSpan(v);
    }


    return 0;

}