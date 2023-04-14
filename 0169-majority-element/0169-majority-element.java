class Solution {
    public int majorityElement(int[] nums) {
        int res = -1, count = 0;
        
        for(int i=0;i<nums.length;i++) {
            if(count == 0) {
                res = nums[i];
            }
            
            if(nums[i] != res) count--;
            else count++;
        }
        
        return res;
    }
}