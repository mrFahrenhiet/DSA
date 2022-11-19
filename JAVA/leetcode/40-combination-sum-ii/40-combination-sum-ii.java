class Solution {
    private void combinations(int[] candidates, List<List<Integer>> res, List<Integer> temp, int target, int i) {
        if(target < 0) return;
        if(target == 0) {
            res.add(new ArrayList<>(temp));
            // System.out.println(temp);
            return;
        }
        for(int j=i;j<candidates.length;j++) {
            if(j > i && candidates[j] == candidates[j-1]) continue;
            temp.add(candidates[j]);
            combinations(candidates, res, temp, target - candidates[j], j+1);
            temp.remove(temp.size()-1);
        }
        return;
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        combinations(candidates, res, temp, target, 0);
        return res;
    }
}