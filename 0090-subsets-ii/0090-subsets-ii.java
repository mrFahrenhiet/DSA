class Solution {
    private List<List<Integer>> res;
    
    private void helper(int[] nums, List<Integer> temp, int i) {
        
        res.add(new ArrayList<Integer>(temp));
        
        for(int j = i;j < nums.length; j++) {
            if(j > i && nums[j] == nums[j-1]) continue;
            temp.add(nums[j]);
            helper(nums, temp, j+1);
            temp.remove(temp.size() - 1);
        }
        
        return;
    }
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        res = new ArrayList<>();
        
        List<Integer> temp = new ArrayList<Integer>();
        
        helper(nums, temp, 0);
        
        return res;
    }
}