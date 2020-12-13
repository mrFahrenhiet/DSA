#include<iostream>
#include<vector>
#include<list>
using namespace std;
template <typename T> 
class Queue {
private:
	int cs;
	list<T> qu;
	
public:
		Queue() {
			this->cs=0;
		}
		void push(T data) {
			this->qu.push_back(data);
		}
		int get_size() {
			return this->qu.size();
		}
		bool is_empty() {
			return this->cs==0;
		}
		void pop() {
			if(!s_empty()) {
				this->cs-=1;
				this->qu.pop_front();
			}
		}
		void front() {
			return this->qu.front();
		}
};
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    q.push(50);
    return 0;

}