#include<bits/stdc++.h>
using namespace std;
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int m,n,test,towers;
    cin>>test;
    for(int t=0;t<test;t++) {
    	cin>>m>>n>>towers;
    	int x[towers];
    	int y[towers];
    	for(int i=0;i<towers;i++) {
    		cin>>x[i]>>y[i];
    	}
    	sort(x,x+towers);
    	sort(y,y+towers);
    	int delx=0,dely=0;
    	for(int i=0;i<towers;i++) {
    		if(i==0) {
    			delx = max(delx,x[i]-0-1);
    			dely = max(dely,y[i]-0-1);
    		}
    		else if(i==towers-1) {
    			delx = max(delx,m-x[i]);
    			dely = max(dely,n-y[i]);
    		}
    		else {
    			delx = max(delx,x[i]-x[i-1]-1);
    			dely = max(dely,y[i]-y[i-1]-1);
    		}

    	}
    	int max_area = delx*dely;
    	cout<<max_area;

    }
    return 0;

}