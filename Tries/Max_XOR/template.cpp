#include <bits/stdc++.h>
using namespace std;
class Trie {
public:
    Trie *left;
    Trie *right;
};

void insert(int a, Trie* head) {
    Trie *curr = head;
    for(int i=31;i>=0;i--) {
        int b = (a>>i)&1;
        if(b==0) {
            if(!curr->left)
                curr->left = new Trie();
            curr = curr->left;
        }
        else {
            if(!curr->right) 
                curr->right = new Trie();
            curr = curr->right;
        }
    }
    return;
}

int find_max_xor(int el,Trie*head) {
    Trie *curr =  head;
    int val = el;
    int maxi = INT_MIN;
    int curr_xor = 0;
    for(int i=31;i>=0;i--) {
        int b = (val>>i)&1;
        if(b==0) {
            if(curr->right) {
                curr = curr->right;
                curr_xor += (int)pow(2,i);
            }
            else {
                curr = curr->left;
            }
        }
        if(b==1) {
            if(curr->left) {
                curr = curr->left;
                curr_xor += (int)pow(2,i);
            }
            else {
                curr = curr->right;
            }
        }
    }
    if(curr_xor>maxi) {
    	maxi = curr_xor;
    }
    return maxi;
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
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    Trie *head = new Trie();
    int result = INT_MIN;
    int curr = arr[0];
    for(int i=1;i<n;i++) {
    	arr[i] = curr^arr[i];
    	 curr = arr[i];
    }
    for(int i=0;i<n;i++) {
        insert(arr[i],head);
        int x = find_max_xor(arr[i],head);
        result = (result>x)?result:x;
    }
    cout<<result;
}
