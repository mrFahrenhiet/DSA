#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Top Down (Rec + Memorization)
vector<int> a(1005,0);
int min_steps_top(int n) {
    int x=n+5,y=n+5,z;
    if(n==1) {
        return 1;
    }
    if(a[n]!=0) {
        return a[n];
    }
    if(n%3==0 && n%2==0) {
        y = min_steps_top(n/3);
        x = min_steps_top(n/2);
    }
    else if(n%2==0) { 
        x = min_steps_top(n/2);
    }
    else if(n%3==0) {
        x = min_steps_top(n/3);
    }
    z = min_steps_top(n-1);
    return a[n] = min(x,min(z,y))+1;

}
//bottom up
int min_steps_bottom(int n) {
    vector<int> dp(1005,0);
    dp[0] = -1;
    dp[1] = 0;
    for(int i=2;i<=n;i++) {
        int x=i+5,y=i+5,z;
        if(i%2==0 && i%3==0) {
            x = dp[i/2];
            y = dp[i/3];
        }
        else if(i%2==0) {
            x = dp[i/2];
        }
        else if(i%3==0) {
            y = dp[i/3];
        }
        z = dp[i-1];
        dp[i] = min(x,min(z,y))+1;
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    cout<<min_steps_bottom(n);
}
