class Solution {
    public int singleNonDuplicate(int[] nums) {
        if(nums.length == 1) return nums[0];
        int left = 2, right = nums.length - 3;
        if(nums[0] != nums[1]) return nums[0];
        if(nums[nums.length - 1] != nums[nums.length - 2]) return nums[nums.length - 1];
        
        while(left <= right) {
            int mid = (left + (right - left)/2);
            if(mid % 2 == 0) {
                if(nums[mid] == nums[mid + 1]) left = mid + 1;
                else if(nums[mid] == nums[mid - 1]) right = mid - 1;
                else return nums[mid];
            }
            else {
                if(nums[mid] == nums[mid - 1]) left = mid + 1;
                else if(nums[mid] == nums[mid + 1]) right = mid - 1;
                else return nums[mid];   
            }
        }
        return -1;
    }
}