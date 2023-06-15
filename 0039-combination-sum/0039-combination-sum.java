class Solution {
    private List<List<Integer>> res;
    private void helper(int[] candidates, List<Integer> temp, int target, int cur) {
        if(target == 0) {
            this.res.add(new ArrayList<Integer>(temp));
            return;
        }
        
        if(cur >= candidates.length) return;
        
        if(target >= candidates[cur]) {
            temp.add(candidates[cur]);
            helper(candidates, temp, target - candidates[cur], cur);
            if(temp.size() > 0) temp.remove(temp.size() - 1);
        }
        
        helper(candidates, temp, target, cur+1);
        
        return;
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        this.res = new ArrayList<>();
        
        List<Integer> temp = new ArrayList<Integer>();
        
        this.helper(candidates, temp, target, 0);
        
        return this.res;
    }
}