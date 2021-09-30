#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int partition_random(vector<int>& arr, int s, int e) {
	srand(time(NULL));
	int random = s + rand() % (e - s);
	swap(arr[e-1], arr[random]);
	int piv = arr[e=1];
	int j = s-1;
	for(int i=s;i<e-1;i++) {
		if(piv < arr[i]) {
			j++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[j+1], arr[e-1]);
	return j+1;
}

int quick_select(vector<int>& arr, int k, int s, int e) {
	if(s>=e) return -1;
	int p = partition_random(arr, s, e);
	if(p==k) return arr[p];
	if(p > k) return quick_select(arr, k, s, p);
	return quick_select(arr, k, p+1, e);
}

int main() {
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++) {
		int no;
		cin>>no;
		arr.push_back(no);
	}
	int k;
	cin>>k;
	int x = quick_select(arr, k, 0, n);
	cout<<x<<endl;
	return 0;
}