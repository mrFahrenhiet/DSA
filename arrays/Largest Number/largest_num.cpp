#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

bool comp(int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string largest_nos(int arr[], int n) {
    sort(arr, arr + n, comp);
    string res = "";
    for(int i=0;i<n;i++) res += to_string(arr[i]);
    return res; 
}
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<largest_nos(arr, n);
    }

	return 0;

}