#include<bits/stdc++.h>
using namespace std;

string simplify(string s) {
	string temp = "",res;
	vector<string> ans;
	s += "/";
	for(int i=0;s[i]!='\0';i++) {
		if(s[i]=='/') {
			if(temp=="")
				continue;
			else if(temp=="..") {
				if(ans.size())
					ans.pop_back();
			}
			else if(temp==".") {
			}
			else {
				ans.push_back(temp);
			}
			temp.clear();
		}
		else {
			temp+=s[i];
		}
	}

	if(ans.size()==0)
		return "/";
	else {
		for(auto itr: ans) {
			res += ("/"+itr);
		}
		return res;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin>>s;
    cout<<simplify(s);
    return 0;

}