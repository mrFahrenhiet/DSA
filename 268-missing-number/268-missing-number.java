class Solution {
    private void swap(int[] nums, int x, int y) {
        int z = nums[x];
        nums[x] = nums[y];
        nums[y] = z;
        return;
    }
    public int missingNumber(int[] nums) {
        int res = -1;
        for(int i=0;i<nums.length;i++) {
            while(nums[i] < nums.length && nums[nums[i]] != nums[i])
                swap(nums, nums[i], i);
        }
        
        for(int i=0;i<nums.length;i++) {
            if(nums[i] != i) return i;
        }
        return nums.length;
    }
}