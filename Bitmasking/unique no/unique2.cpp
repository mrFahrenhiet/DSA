#include<iostream>
#include<vector>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    vector<int> v;
    cin>>n;
    int no,xr=0,pos=0;
    for(int i=0;i<n;i++) {
        cin>>no;
        v.push_back(no);
        xr = xr^no;
    }
    int temp = xr;
    while(temp>0) {
        int last = temp&1;
        if(last==1) {
            break;
        }
        pos++;
        temp = temp>>1;
    }
    int mask = 1<<pos;
    int a=0;
    for(int i=0;i<v.size();i++) {
        if((v[i]&mask)>0) {
            a=a^v[i];
        }
    }
    cout<<a;
    int b=xr^a;
    cout<<" "<<b;

    
    return 0;

}