#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
private:
    string table[10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
    string search_in[11] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
public:
    void get_pat(vector<string>& lst, string s, string o, int i) {
        if(i>=s.length()) {
            lst.push_back(o);
            return;
        }
        int digit = s[i]-'0';
        for(int j=0;j<this->table[digit].length();j++) {
            o.push_back(this->table[digit][j]);
            get_pat(lst, s, o, i+1);
            o.pop_back();
        }
        return;
    }

    vector<string> get_names(vector<string>& pats) {
        vector<string> res;
        for(int l=0;l<pats.size();l++) {
            for(int k=0;k<11;k++) {
                if(search_in[k].find(pats[l]) != string::npos) res.push_back(search_in[k]); 
            }
        }
        return res;
    }

    void put_names(string s) {
        string o;
        vector<string> pats, res;
        get_pat(pats, s, o, 0);
        res = get_names(pats);
        for(auto r: res) cout<<r<<endl;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin>>s;
    Solution sol;
    sol.put_names(s);
}
