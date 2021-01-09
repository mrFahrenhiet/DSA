class Solution {
public:
    bool constructUtil(int n, vector<int> &ans, vector<bool> &used, int i) {
        if(i == ans.size()) return true;
        if(ans[i]) return constructUtil(n, ans, used, i+1);
        for(int j=n;j>0;j--) {
            if(used[j]) continue;
            if(j != 1 and (ans[i + j] or i + j >= ans.size())) continue;
            used[j] = true;
            ans[i] = j;
            if(j!=1) ans[i + j] = j;
            if(constructUtil(n, ans, used, i+1)) return true;
            ans[i] = 0;
            if(j!=1) ans[i+j] = 0;
            used[j] = false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        if (n == 1) return {1};
        vector<bool> used(n + 1, false);
        vector<int> ans(2 * n - 1, 0);
        constructUtil(n, ans, used, 0);
        return ans;
    }
};