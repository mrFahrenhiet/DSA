class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new LinkedList<>(); ;
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++) {
            int l = i+1, r = nums.length-1;
            int s = 0 - nums[i];
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                while(l<r) {
                    if(nums[l] + nums[r] == s){
                        res.add(Arrays.asList(nums[i], nums[l], nums[r]));
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;
                        l++; r--;
                    }
                    else if(nums[l] + nums[r] > s) r--;
                    else l++;
                }
            }
        }
        return res;
    }
}