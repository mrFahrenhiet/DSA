#include<iostream>
#include<vector>
using namespace std;
template <typename T> 
class Queue {
private:
	int ms,cs,f,r;
	T *arr;
public:
		Queue(int ds=5) {
			ms =ds;
			cs =0;
			f=0;
			r=ms-1;
			arr = new T[ms];
		}
		bool is_full() {
			return cs>=ms;
		}
		void push(T data) {
			if(!is_full()) {
				r = (r+1)%ms;
				arr[r] = data;
				cs++;
			}
			else {
				throw "Array is Full cannot push";
			}
		}
		int get_size() {
			return ms;
		}
		bool is_empty() {
			return cs<=0;
		}
		void pop() {
			if(!is_empty()) {
				f = (f+1)%ms;
				cs--;
			}
			else {
				throw "Array is empty cannot pop";
			}
		}
		T get_front() {
			return arr[f];
		}
};
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Queue<int> q(6);
    for(int i=0;i<6;i++) {
    	q.push(i);
    }
    q.pop();
    q.push(7);
    cout<<q.get_size()<<endl;
    while(!q.is_empty()) {
    	cout<<q.get_front()<<" ";
    	q.pop();
    }
    return 0;

}