#include <iostream>
#include<vector>
using namespace std;
int lin_search(vector<int> a,int s) {
    int i = a.size();
    if(a[i-1]==s) {
        return i-1;
    }
    if(a.size()<=1) {
        return -1;
    }
    a.pop_back();
    return lin_search(a,s);
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
    int s;
    cin>>s;
    int j = lin_search(v,s);
    cout<<j;
}
