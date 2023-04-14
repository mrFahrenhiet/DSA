class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> res = new ArrayList<Integer>();
        int nums1 = 0, count1 = 0, nums2 = 0, count2 = 0;
        
        for(int i=0;i<nums.length;i++) {
            if(nums[i] == nums1) count1++;
            else if(nums[i] == nums2) count2++;
            else if(count1 == 0) {
                nums1 = nums[i];
                count1++;
            }
            else if(count2 == 0) {
                nums2 = nums[i];
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = 0; 
        count2 = 0;
        
        for(int i=0;i<nums.length;i++) {
            if(nums1 == nums[i]) count1++;
            if(nums2 == nums[i]) count2++;
        }
        
        if(count1 > nums.length / 3) res.add(nums1);
        if(count2 > nums.length / 3 && nums1 != nums2) res.add(nums2);
        
        return res;
    }
}