class Solution {
    private int MOD = 1000000007;
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int s = 0, e = nums.length - 1, res = 0;
        int[] pow = new int[nums.length+1];
        pow[0] = 1;
        for(int i=1;i<=nums.length;i++) pow[i] = (pow[i-1] * 2) % MOD;
        while(s <= e) {
            if(nums[s] + nums[e] <= target) {
                res = (res +  pow[e-s]) % MOD;
                s++;
            }
            else e--;
        }
        return res;
    }
}