class Solution {
    private boolean helper(int[] nums, int[] dp, int i) {
        if(i >= nums.length) return true;
        if(dp[i] != -1) return dp[i] > 0;
        
        // Equality
        if(i < nums.length - 1 && nums[i+1] == nums[i]) {
            if(helper(nums, dp, i+2)) {
                dp[i] = 1;
                return true;
            }
            if(i < nums.length - 2 && nums[i+2] == nums[i+1] && nums[i] == nums[i+1]) {
                if(helper(nums, dp, i+3)) {
                    dp[i] = 1;
                    return true;
                }
            }
        }
        
        // Concecutive
        if(i < nums.length - 2 && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) {
            if(helper(nums, dp, i+3)) {
                dp[i] = 1;
                return true;
            }
        }
        
        dp[i] = 0;
        
        return false;
    }
    public boolean validPartition(int[] nums) {
        int[] dp = new int[nums.length];
        for(int i=0;i<nums.length;i++) dp[i] = -1;
        
        return helper(nums, dp, 0);
    }
}