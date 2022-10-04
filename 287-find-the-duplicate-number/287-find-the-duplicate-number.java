class Solution {
    private void swap(int[] arr, int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
        return;
    }
    public int findDuplicate(int[] nums) {
        for(int i=0;i<nums.length;i++) {
            while(nums[i] != nums[nums[i]-1]) swap(nums, i, nums[i] - 1);
            if(nums[i] == nums[nums[i]-1] && nums[i] - 1 != i) return nums[i];
        }
        return -1;
    }
}