#include <bits/stdc++.h>
using namespace std;
int no_rt_triangle(int x[],int y[],int n) {
    unordered_map<int,int> mx;
    unordered_map<int,int> my;
    for(int i=0;i<n;i++) {
        if(mx.count(x[i])>=1) {
            mx[x[i]]++;
        }
        else {
            mx[x[i]] = 1;
        }
        if(my.count(y[i])>=1) {
            my[y[i]]++;
        }
        else {
            my[y[i]] = 1;
        }
    }
    int rt = 0;
    for(int i=0;i<n;i++) {
        pair<int,int> pi (x[i],y[i]);
        int n1 = mx[x[i]];
        int n2 = my[y[i]];
        rt+=(n1-1)*(n2-1);
    }
    return rt;
}
int main() {
    int n;
    cin>>n;
    int x[n],y[n];
    for(int i=0;i<n;i++) {
        cin>>x[i];
    }
    for(int i=0;i<n;i++) {
        cin>>y[i];
    }
    int l = no_rt_triangle(x,y,n);
    cout<<l;
}
