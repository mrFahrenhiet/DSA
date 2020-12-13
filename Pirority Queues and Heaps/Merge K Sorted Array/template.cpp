#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int,int>> pi;
void merge(vector<vector<int>> &a) {
	vector<int> b;
	priority_queue<pi, vector<pi>, greater<pi>> q;
	int k = a.size();
	int j =0;
	for(int i=0;i<k;i++) {
			q.push({a[i][0],{i,0}});
	}
	while(!q.empty()) {
		pi x = q.top();
		q.pop();
		int row = x.second.first;
		int col = x.second.second;
		b.push_back(x.first);
		if(col+1<a[row].size())
			q.push(make_pair(a[row][col+1],make_pair(row,col+1)));
	}
	for(int l=0;l<b.size();l++) {
		cout<<b[l]<<" ";
	}
	return;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int k,n;
    cin>>k;
    cin>>n;
    vector<vector<int>> a;
    for(int i=0;i<k;i++) {
    	a.push_back(vector<int>());
    	for(int j=0;j<n;j++) {
    		int no;
    		cin>>no;
    		a[i].push_back(no);
    	}
    }
    merge(a);
    return 0;

}