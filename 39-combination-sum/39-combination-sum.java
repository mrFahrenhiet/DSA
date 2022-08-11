class Solution {
    private void combiSum(List<List<Integer>> res, List<Integer> temp, int[] candidates, int target, int i) {
        if(i >= candidates.length || target < 0) return;
        if(target == 0) {
            if(temp.size() > 0) res.add(new ArrayList<Integer>(temp));
            return;
        }
        temp.add(candidates[i]);
        combiSum(res, temp, candidates, target - candidates[i], i);
        temp.remove(temp.size()-1);
        combiSum(res, temp, candidates, target, i+1);
        return;
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<Integer>();
        combiSum(res, temp, candidates, target, 0);
        return res;
    }
}