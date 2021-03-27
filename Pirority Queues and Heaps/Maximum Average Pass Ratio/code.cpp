#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Classes {
public:
    int pass;
    int tol;
    Classes(int pass, int tol)
        :pass(pass), tol(tol)
    {}
};

bool operator<(const Classes& c1, const Classes& c2) {
    double newPassRatio1 = (double)(c1.pass+1)/(double)(c1.tol+1);
    double oldPassRatio1 = (double)(c1.pass)/(double)(c1.tol);
    double delta1 = newPassRatio1 - oldPassRatio1;
    double newPassRatio2 = (double)(c2.pass+1)/(double)(c2.tol+1);
    double oldPassRatio2 = (double)(c2.pass)/(double)(c2.tol);
    double delta2 = newPassRatio2 - oldPassRatio2;
    return delta1 < delta2;
}

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Classes> cls;
        for(auto c: classes) {
            cls.push(Classes(c[0], c[1]));
        }
        while(extraStudents) {
            Classes c = cls.top();
            cls.pop();
            c.pass++;
            c.tol++;
            cls.push(c);
            extraStudents--;
        }
        double res = 0, sz = cls.size();
        while(!cls.empty()) {
            Classes c = cls.top();
            double t = (double)(c.pass)/(double)(c.tol);
            res += t;
            cls.pop();
        }
        return res/sz;
    }
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<vector<int>> classes(n, vector<int>(n, 0));
    for(int i=0; i<n;i++) {
        for(int j=0;j<2;j++) {
            int no;
            cin>>no;
            classes[i][j] = no;
        }
    }
    int extraStudents;
    cin>>extraStudents;
    Solution s;
    cout<<"Maximum class pass ratio = "<<s.maxAverageRatio(classes, extraStudents);
    return 0;

}