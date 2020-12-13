#include<iostream>
#include<string>
using namespace std;


long int find_max_len(string s) {   //bbbbabba
  unsigned int max=0,count=0;
  char *i = &s[0];
  char *j = &s[1];
  while(*i!='\0' && *j!='\0') {
    if(*i==*j){
      j++;
      count++;
      if(max<=count){
        max=count+1;
      }
    }
    else {
      i++;
      j++;
      count=0;
    }
  }
  return max;
}


int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
  string s;
  char *i = &s[0];
  char *j = &s[1];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      for(int k=i;k<=j;k++) {
        
      }
    }
  }
  
  return 0;
}