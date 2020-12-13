#include<iostream>
using namespace std;
int main() {
    long int N,hh,hhy;
    double n,hy,h;
    cin>>N;
    n=N;
    if(N%2==0) {
        h = ((n*n)/4)-1;
        hy = ((n*n)/4)+1;
        hh = ((N*N)/4)-1;
        hhy = ((N*N)/4)+1;
        if(h>=0 && hy>=0 && n>=0) {
            cout<<hh<<" "<<hhy;
        }
        else {
            cout<<-1;
        }
    }
    else {
        h=((n+1)*(n-1))/2;
        hh = ((N+1)*(N-1))/2;
        hy = (((n+1)*(n+1))/4)+(((n-1)*(n-1))/4);
        hhy = (((N+1)*(N+1))/4)+(((N-1)*(N-1))/4);
        if(h>=0 && hy>=0 && n>=0) {
            cout<<hh<<" "<<hhy;

        }
        else {
            cout<<-1;
        }
    }
	return 0;
}