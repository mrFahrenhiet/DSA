#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool checkSign(int a, int b) {
	return ((a>0 and b>0) or (a<0 and b<0) or (a<0 and b>0));
}
vector<int> arrStack(vector<int> &v) {
	stack<int> s;
	vector<int> res;
	for(auto itm: v) {
		while(!s.empty() and abs(s.top())<abs(itm) and !checkSign(s.top(), itm)) {
			s.pop();
		}
		if(!s.empty() and abs(s.top())==abs(itm) and !checkSign(s.top(), itm)) {
			s.pop();
			continue;
		}
		if(s.empty() or checkSign(s.top(),itm))
			s.push(itm);
	}
    while(!s.empty()) {
		res.push_back(s.top());
		s.pop();
    }
    reverse(res.begin(), res.end());
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
    	int no;
    	cin>>no;
    	v.push_back(no);
    }
   	vector<int> res = arrStack(v);
   	for(auto itr: res) {
   		cout<<itr<<" ";
   	}

    return 0;

}