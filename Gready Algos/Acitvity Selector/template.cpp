#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> p1, pair<int,int> p2) {
	return p1.second<p2.second;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	vector<pair<int,int>> m;
	int test;
	cin>>test;
	for (int t = 0; t < test;t++) {
		int n;
		cin>>n;
		for(int i=0;i<n;i++) {
			int stime,etime;
			cin>>stime>>etime;
			m.push_back(make_pair(stime,etime));
		}
		sort(m.begin(),m.end(),compare);
		int c = 1;
		int time = m[0].second; 
		for(int i=1;i<m.size();i++) {
			if(time>m[i].first) {
				continue;
			}
			c++;
			time = m[i].second;
		}
		cout<<c<<endl;
		m.clear();
	}
    return 0;

}