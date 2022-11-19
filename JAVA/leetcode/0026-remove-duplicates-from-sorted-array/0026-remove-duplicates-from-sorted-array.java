class Solution {
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = arr[i];
        return;
    }
    public int removeDuplicates(int[] nums) {
        int i = 0, j = i + 1;
        while(j < nums.length) {
            while(j < nums.length && nums[i] == nums[j]) j++;
            if(j >= nums.length) return i+1;
            swap(nums, i+1, j);
            i++;
            j++;
        }
        return i+1;
    }
}