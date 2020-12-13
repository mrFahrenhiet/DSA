#include <iostream>
#include<vector>
using namespace std;
int bin_s(vector<int> a,int s,int l,int p) {
    int m = (l+s)/2;
    if(s>l) {
        return -1;
    }
    if(a[m]==p) {
        return m;
    }
    else if(a[m]<p) {
        return bin_s(a,m+1,l,p);
    }
    else {
        return bin_s(a,s,m-1,p);
    }

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
    int s,l,p;
    s=0;
    l=n-1;
    cin>>p;
    int pos = bin_s(v,s,l,p);
    cout<<pos<<endl;
    
}
