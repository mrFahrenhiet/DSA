class Solution {
    private List<List<Integer>> res;
    
    private void helper(int[] nums, ArrayList<Integer> temp, boolean[] visited) {
        if(temp.size() >= nums.length) {
            res.add(new ArrayList<Integer>(temp));
            return;
        }
        
        for(int i = 0; i < nums.length; i++) {
            if(!visited[i] && (i == 0 || nums[i] != nums[i-1] || visited[i-1])) {
                temp.add(nums[i]);
                visited[i] = true;
                helper(nums, temp, visited);
                temp.remove(temp.size() - 1);
                visited[i] = false;
            }
        }
                
        return;
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        res = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        Arrays.sort(nums);
        ArrayList<Integer> temp = new ArrayList<Integer>();
        
        helper(nums, temp, visited);
        return res;
    }
}