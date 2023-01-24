class Solution {
    private List<List<Integer>> res;
    
    private void helper(int[] nums, List<Integer> temp, int i) {
        if(temp.size() > 1) res.add(new ArrayList<Integer>(temp));
        
        HashSet<Integer> freqMap = new HashSet<Integer>();
        
        for(int j=i;j<nums.length;j++) {
            if((temp.size() == 0 || temp.get(temp.size() - 1) <= nums[j]) && !freqMap.contains(nums[j])) {
                temp.add(nums[j]);
                freqMap.add(nums[j]);
                helper(nums, temp, j + 1);
                temp.remove(temp.size() - 1);
            }
        }
        return;
    }
    public List<List<Integer>> findSubsequences(int[] nums) {
        res = new ArrayList<>();
        List<Integer> temp = new ArrayList<Integer>();
        
        helper(nums, temp, 0);
        
        return res;
    }
}