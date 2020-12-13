#include <iostream>
#include <vector>
using namespace std;
void bubble(vector<int> &a,int i,int n) {
    if(n==1) {
        return;
    }
    if(i==n-1) {
        return bubble(a,0,n-1);
    }
    if(a[i]>a[i+1]) {
        int t =a[i];
        a[i] = a[i+1];
        a[i+1] = t;
    }
    bubble(a,i+1,n);

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
    bubble(v,0,n);
    for(int i=0;i<n;i++) {
       cout<<v[i]; 
    }
}
