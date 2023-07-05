class Solution {
    public int singleNonDuplicate(int[] nums) {
        int st = 0, en = nums.length - 1;
        while(st <= en) {
            int mid = (st + (en - st) / 2);
            if(mid > 0 && nums[mid] == nums[mid - 1] && mid % 2 == 0)
                en = mid;
            else if(mid > 0 && nums[mid] == nums[mid - 1] && mid % 2 != 0)
                st = mid + 1;
            else if(mid < nums.length - 1 && nums[mid] == nums[mid + 1] && mid % 2 == 0)
                st = mid + 1;
            else if(mid < nums.length - 1 && nums[mid] == nums[mid + 1] && mid % 2 != 0)
                en = mid;
            else
                return nums[mid];
        }
        
        return -1;
    }
}