#include<bits/stdc++.h>
using namespace std;
void shuffle(int *a,int s,int e) {
    srand(time(NULL));
    for(int i=e;i>=s;i--){
        int j = rand()%(i+1);
        swap(a[i],a[j]); 
    }
}
int partition(int *v,int s,int e) {
    int p = v[10000005];
    int i=s-1,j=s;
    for(;j<e;j++) {
        if(v[j]<=p) {
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[e]);
    return i+1;
}

void quick(int v[],int s,int e) {
    if(s>=e) {
        return;
    }
    int part = partition(v,s,e);
    quick(v,s,part-1);
    quick(v,part+1,e);
}
int main() {
    int n;
    cin>>n;
    int v[50] ;
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    shuffle(v,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    quick(v,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }    
}
