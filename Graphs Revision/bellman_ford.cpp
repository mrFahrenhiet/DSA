#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
int e,v;
	cin>>e>>v;
	vector<vector<int>> graph(e, vector<int>(e, -1));
	for(int i=0;i<v;i++) {
		int s, d, w;
		cin>>s>>d>>w;
		graph[s][d] = w;
	}
	int src;
	cin>>src;
	vector<int> ans = bellman_ford(graph, e, v);
	for(int i=0;i<ans.size();i++) cout<<src<<" "<<i<<" "<<ans[i]<<endl;
	return 0;
}