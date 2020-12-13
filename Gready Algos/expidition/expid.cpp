#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1, pair<int,int> p2) {
	return p1.first>p2.first;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    bool flag=true;
    int n,f,d,F,D,prev=0;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) {
    	cin>>d>>f;
    	v.push_back(make_pair(d,f));
    }
    sort(v.begin(), v.end(),comp);
    cin>>D>>F;
    for(int i=0;i<n;i++) {
    	v[i].first = D-v[i].first;
    }
    int x =0,ans=0;
    priority_queue<int> pq;
    while(x<n) {
    	if(F>=v[x].first-prev) {
    		pq.push(v[x].second);
    		F = F - v[x].first + prev;
    		prev = v[x].first;
    	}
    	else {
    		if(!pq.empty()) {
    			F += pq.top();
    			pq.pop();
    			ans+=1;
    			continue;
    		}
    		flag=false;
    		break;
    	}
    	x++;
    }
    if(flag==false) {
    	cout<<-1<<endl;
    }
    else {
    	D = D - v[n-1].first;
    	if(F>=D) {
    		cout<<ans<<endl;
    	}
    	else {
    		if(pq.empty()) {
    			flag = false;
    			cout<<-1<<endl;
    		}
    		else {
    			F += pq.top();
    			pq.pop();
    			cout<<ans+1<<endl; 
    		}
    	}
    }
    return 0;

}