#include <iostream>
using namespace std;
void towerofhanoi(int n,char src, char dist, char helper) {
    if(n==0) {
        return;
    }
    towerofhanoi(n-1,src,helper,dist);
    cout<<n<<"\t"<<src<<"\t"<<dist<<endl;
    towerofhanoi(n-1,helper,dist,src);
}
int main() {
    int n;
    cin>>n;
    char s,d,h;
    cin>>s;
    cin>>d;
    cin>>h;
    cout<<"Disk\t"<<"Src\t"<<"Destination"<<endl;
    towerofhanoi(n,s,d,h);
}
