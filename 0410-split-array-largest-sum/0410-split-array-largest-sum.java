class Solution {
    private boolean isFeasible(int[] nums, int k, int maxSubArrSum) {
        int subArrSum = 0;
        
        for(int i=0;i<nums.length;i++) {            
            subArrSum += nums[i];
            
            if(subArrSum > maxSubArrSum) {
                k--;
                subArrSum = nums[i];
            }
            
            if(k <= 0) return false;
        }
        
        return true;
    }
    public int splitArray(int[] nums, int k) {
        int low = 0, high = 0;
        
        for(int num: nums) {
            high += num;
            low = Math.max(low, num);
        }
                
        while(low < high) {
            int mid = (low + (high - low) / 2);
            if(isFeasible(nums, k, mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
}