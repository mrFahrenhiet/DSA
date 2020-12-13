#include <iostream>
using namespace std;
int main() {
    int n,x,i=0,step=0;
    cin>>n;
    x=n;
    while(x>0) {
        i=0;
        int temp =x;
        while(temp>0){
            i++;
            temp=temp>>1;
        }
        int j = i-1;
        int mask = 1<<j;
        int diff = x-mask;
        x= diff;
        step++;
    }
    cout<<step<<" ";
}
