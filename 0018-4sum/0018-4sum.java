class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        
        Arrays.sort(nums);
        
        for(int i=0;i<nums.length;i++) {
            for(int j=i+1;j<nums.length;j++) {
                long tempTarget = (long)target - ((long)nums[i] + (long)nums[j]);
                
                if(tempTarget < Integer.MAX_VALUE || tempTarget > Integer.MIN_VALUE) {
                
                int left = j+1, right = nums.length - 1;
                while(left < right) {
                    if((long)(nums[left] + nums[right]) == tempTarget) {
                        int num3 = nums[left];
                        int num4 = nums[right];
                        res.add(new ArrayList<>(List.of(nums[i], nums[j], num3, num4)));
                        left++;
                        right--;
                        while(left < right && nums[left] == num3 && nums[right] == num4) {
                            left++;
                            right--;
                        }
                    }
                    else if((long)(nums[left] + nums[right]) > tempTarget) right--;
                    else left++;
                }
                }
                while(j < nums.length-1 && nums[j] == nums[j+1]) j++;
            }
            while(i < nums.length-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
}