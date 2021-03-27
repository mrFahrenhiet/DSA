#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Solution {
public:
	int quickestWayUp(int n, vector<vector<int>>& ladders, vector<vector<int>>& snakes) {
		vector<int> moves(n+1, 0);
		vector<bool> visited(n+1, false);
		queue<pair<int,int>> q;
		for(int i=0;i<ladders.size();i++) moves[ladders[i][0]] = ladders[i][1];
		for(int j=0;j<snakes.size();j++) moves[snakes[j][0]] =  snakes[j][1];
		q.push({1,0});
		visited[1] = true;
		while(!q.empty()) {
			pair<int,int> temp = q.front();
			q.pop();
			cout<<temp.first<<endl;
			if(temp.first==n) return temp.second;
			for(int i=1+temp.first;i<=6+temp.first;i++) {
				if(!visited[i]) {
					visited[i] = true;
					pair<int,int> nw;
					nw.second = temp.second + 1;
					if(moves[i]!=-1) nw.first = moves[i];
					else nw.first = i;
					q.push(nw);
				}
			}
		}
		return -1;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--) {
		int n,l,s;
		cin>>n;
		cin>>l;
		vector<vector<int>> ladders(l, vector<int>(2,0));
		for(int i=0;i<l;i++) {
			int from, to;
			cin>>from>>to;
			ladders[i][0] = from;
			ladders[i][1] = to;
		}
		cin>>s;
		vector<vector<int>> snakes(s, vector<int>(2,0));
		for(int i=0;i<s;i++) {
			int from, to;
			cin>>from>>to;
			snakes[i][0] = from;
			snakes[i][1] = to;
		}
		Solution Sol;
		int res = Sol.quickestWayUp(n, ladders, snakes);
		cout<<res<<endl;
	}
	return 0;
}