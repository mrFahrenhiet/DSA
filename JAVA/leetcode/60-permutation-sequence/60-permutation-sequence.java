class Solution {
    public String getPermutation(int n, int k) {
        ArrayList<Integer> num = new ArrayList<Integer>();
        StringBuilder res = new StringBuilder("");
        int[] fact = new int[n+1];
        
        fact[0] = 1;
        for(int i=1;i<=n;i++) fact[i] = fact[i-1]*i;
        
        for(int i=1;i<=n;i++) num.add(i);
        
        k--;
        for(int i=n-1;i>=0;i--) {
            int idx = k / fact[i];
            res.append(String.valueOf(num.get(idx)));
            num.remove(idx);
            k -= idx * fact[i];
        }
        
        return String.valueOf(res);
    }
}