#include <iostream>
#include<vector>
using namespace std;
void merge(vector<int> &v,int s,int e) {
    int m = (s+e)/2;
    int i = s,j=m+1,k=s;
    int temp[100];
    while(i<=m && j<=e) {
        if(v[i]>v[j]) {
            temp[k++] = v[j++];
        }
        else {
            temp[k++] = v[i++];
        }
    }
    while(i<=m) {
        temp[k++] = v[i++];
    }
    while(j<=e){
        temp[k++] = v[j++];
    }
    for(int b=s;b<=e;b++) {
        v[b] = temp[b];
    }
}
void mergesort(vector<int> &v,int s,int e) {
    if(s>=e) {
        return;
    }
    int m = (s+e)/2;
    mergesort(v,s,m);
    mergesort(v,m+1,e);
    merge(v,s,e);
}
int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int no;
        cin>>no;
        v.push_back(no);
    }
    mergesort(v,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
}
