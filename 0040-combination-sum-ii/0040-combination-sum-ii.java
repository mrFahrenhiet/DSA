class Solution {
    private List<List<Integer>> res;
    private void helper(int[] candidates, int target, List<Integer> temp, int i) {
        if(target == 0) {
            res.add(new ArrayList<Integer>(temp));
            return;
        }
        
        for(int j=i;j<candidates.length;j++) {
            if(target - candidates[j] < 0 || (j != i && candidates[j-1] == candidates[j]))
                continue;
            
            temp.add(candidates[j]);
            helper(candidates, target - candidates[j], temp, j+1);
            temp.remove(temp.size() - 1);
        }
        
        return;
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        res = new ArrayList<>();
        Arrays.sort(candidates);
        List<Integer> temp = new ArrayList<Integer>();
        helper(candidates, target, temp, 0);
        return res;
    }
}