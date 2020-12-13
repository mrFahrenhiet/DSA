#include<bits/stdc++.h>
using namespace std;
template <typename T>
class queue_pop_eff {
private:
	queue<T> a,b;
public:
	bool empty() {
		return a.empty();
	}
	void pop() {
		if(!a.empty) {
			a.pop();
		}
	}
	void push(int data) {
		if(a.empty()) {
			a.push(data);
		}
		else if(a.size()==1) {
			b.push(data);
		}
		
	}
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    return 0;

}