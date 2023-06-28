class Solution {
    private List<List<Integer>> res;
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
    private void helper(int[] nums, List<Integer> temp, int i) {
        if(i >= nums.length) {
            res.add(new ArrayList<Integer>(temp));
            return;
        }
        
        for(int j=i;j<nums.length;j++) {
            swap(nums, i, j);
            temp.add(nums[i]);
            
            helper(nums, temp, i+1);
            
            swap(nums, i, j);
            temp.remove(temp.size() - 1);
        }
        
            // temp.add(nums[k]);
        
//         res.add(new ArrayList<Integer>(temp));
        
//         for(int k=0;k<nums.length;k++)
//             temp.remove(k);

        return;
    }
    public List<List<Integer>> permute(int[] nums) {
        res = new ArrayList<>();
        List<Integer> temp = new ArrayList<Integer>();
        
        helper(nums, temp, 0);
        
        return res;
    }
}