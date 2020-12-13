#include<iostream>
#include<vector>
using namespace std;
int count=0;
void sub(char *in,char*out,int i,int j) {
	if(in[i]=='\0') {
		out[j]='\0';
		cout<<out<<" ";
		count++;
		return;
	}
	//Rec include
	sub(in,out,i+1,j);
	out[j] = in[i];
	sub(in,out,i+1,j+1);
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    char a[100],t[100];
    cin>>a;
    sub(a,t,0,0);
    cout<<count;
    return 0;

}