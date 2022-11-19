class Solution {
    private void helper(int[] nums, int i, List<Integer> arr, List<List<Integer>> res) {
        if(i >= nums.length) {
            res.add(new ArrayList<Integer>(arr));
            return;
        }
        arr.add(nums[i]);
        helper(nums, i+1, arr, res);
        int temp = arr.get(arr.size() - 1);
        int inc = i+1;
        arr.remove(arr.size() - 1);
        while(inc < nums.length && temp == nums[inc]) inc++;
        helper(nums, inc, arr, res);
        return;
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> arr = new ArrayList<Integer>();
        Arrays.sort(nums);
        helper(nums, 0, arr, res);
        return res;
    }
}