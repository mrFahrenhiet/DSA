#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void avgWindow(vector<float> &v, int winSize) {
	float sum = 0;
	deque<float> dq;
	vector<float> res;
	if(winSize==0) return;
	for(int i=0;i<v.size();i++) {
		if(winSize==1) {
			res.push_back(v[i]);
		}
		else if(i<winSize) {
			sum += v[i];
			dq.push_back(i);
			res.push_back(sum/dq.size());
		}
		else {
			sum -= v[dq.front()];
			sum += v[i];
			dq.pop_front();
			dq.push_back(i);
			res.push_back(sum/dq.size());
		}
	}
	for(auto itm: res) cout<<fixed<<setprecision(4)<<itm<<" ";
	return;
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
    float no;
    vector<float> v;
    while(no!=-1) {
    	cin>>no;
    	if(no!=-1) v.push_back(no);
    }
    avgWindow(v, n);
    return 0;

}