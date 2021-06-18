#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int min_stops(int stations[1000][2], int n, int target, int start_fuel) {
	int stops = 0, i = 0, range = start_fuel;
	priority_queue<int> max_fuel;
	while(range<target) {
		while(i < n and range >= stations[i][0]) max_fuel.push(stations[i++][1]);
		if(max_fuel.empty()) return -1;
		range += max_fuel.top();
		max_fuel.pop();
		stops++;
	}
	return stops;
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
	int stations[1000][2];
	while(t--) {
		memset(stations, 0, sizeof(stations));
		int n, tar, st_f;
		cin>>n>>tar>>st_f;
		for(int i=0;i<n;i++) cin>>stations[i][0]>>stations[i][1];
		cout<<min_stops(stations, n, tar, st_f)<<endl;
	}
	return 0;

}