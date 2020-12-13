#include<bits/stdc++.h>
using namespace std;
void find_intersec(vector<pair <int,int>> &v, int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			v.push_back(make_pair(v[i].first,v[j].second));
		}
	}
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++) {
		if(v[i].first==v[i+1].first && v[i].second==v[i+1].second ) {
			v[i].first = -100;
			v[i].second = -100;
		}
    	cout<<v[i].first<<" "<<v[i].second<<endl;
    }
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
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++) {
    	int f,s;
    	cin>>f>>s;
    	vp.push_back(make_pair(f,s));
    }
    find_intersec(vp,n);
    // for(int i=0;i<vp.size();i++) {
    // 	cout<<vp[i].first<<" "<<vp[i].second<<endl;
    // }
    return 0;

}