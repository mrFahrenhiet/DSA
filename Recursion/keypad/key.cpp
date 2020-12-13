#include<iostream>
#include<string>
using namespace std;
char key[][10] = {" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(char *a,char *b,int i,int j) {
	//base
	if(a[i]=='\0') {
		b[j] = '\0';
		cout<<b<<endl;
		return;
	}
	int d = a[i]-'0';
	// if(d==0) {
	// 	keypad(a,b,i+1,j);
	// }
	for(int k=0;key[d][k]!='\0';k++) {
		b[j] = key[d][k];
		keypad(a,b,i+1,j+1);
	}
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    char in[100],out[100];
    cin>>in;
    keypad(in,out,0,0);

    return 0;

}