class Solution {
    private int helper(List<Integer> nums, Integer[][] dp, int cur, int target) {
        if(cur >= nums.size() && target > 0) return Integer.MIN_VALUE;
        if(nums.size() <= cur || target == 0) return 0;
        if(dp[cur][target] != null) return dp[cur][target];
        int res = 0;
        int incl = 0;
        
        if(target - nums.get(cur) >= 0) {
            incl = helper(nums, dp, cur+1, target - nums.get(cur)) + 1;
        }
        
        int excl = helper(nums, dp, cur+1, target);
        
        if(excl < 0 && incl == 0 || incl < 0 && excl == 0)
            return dp[cur][target] = Integer.MIN_VALUE;
        
        res += Math.max(incl, excl);
        
        return dp[cur][target] = res;
    }
    public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
        Integer[][] dp = new Integer[nums.size()][target + 1];

        int res = helper(nums, dp, 0, target);
        
        return res <= 0 ? -1 : res;
    }
}