#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool minSubArrUitl(vector<int> &nums, int s, int k) {
    int i = 0, j = 0, sum = 0;
    for(;j<nums.size();j++) {
        sum += nums[j];
        while(j-i+1>k) {
            sum -= nums[i];
            i++;
        }
        if(sum>=s) return true;
    }
    return false;
}
int minSubArr(vector<int> &nums, int s) {
    int high = nums.size(), low = 1, ans = INT_MAX;
    while(low<=high) {
        int mid = (low+high)/2;
        if(minSubArrUitl(nums, s, mid)) {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return (ans==INT_MAX?-1: ans);
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int no;
        cin>>no;
        v.push_back(no);
    }
    int k;
    cin>>k;
    int x = minSubArr(v, k);
    cout<<x<<endl;
    return 0;

}