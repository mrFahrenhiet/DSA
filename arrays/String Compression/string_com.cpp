#include<iostream>
#include<string>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin>>s;
    char *head = &s[0];
    char *next = &s[1];
    int count=0;
    char ch;
    while(*head!='\0') {
        if(*head==*next) 
        {
            next++;
            count++;
        }
        else 
        {   
            ch = *head;
            head = next;
            next++;
            cout<<ch<<count+1;
            count=0;
        }
    }
	return 0;

}