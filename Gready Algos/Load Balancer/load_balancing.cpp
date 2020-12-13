#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    int s =0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        s+=a[i];
    }
    if(s%n!=0) {
        cout<<-1;
    }
    else {
        int p = s/n,maxi=0,sum=0;
        for(int i=0,j=1;i<n,j<=n;i++,j++) {
            sum+=a[i];
            if(sum>j*p) {
                maxi = max(maxi,sum-j*p);
            }
            else {
                maxi = max(maxi,j*p-sum);
            }
        }
        cout<<maxi;
    }
    

}
