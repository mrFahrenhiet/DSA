class Solution {
    private void swap(int[] nums, int i1, int i2) {
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
        return;
    }
    
    public int firstMissingPositive(int[] nums) {
        for(int i=0;i<nums.length;i++) {
           while((nums[i] <= nums.length && nums[i] > 0) && nums[nums[i]-1] != nums[i]) swap(nums, nums[i] - 1, i);
        }
        
        for(int i=0;i<nums.length;i++) {
            if((nums[i] > nums.length || nums[i] <= 0) || nums[i] - 1 != i)
                return i+1;
        }
        
        return nums.length + 1;
    }
}