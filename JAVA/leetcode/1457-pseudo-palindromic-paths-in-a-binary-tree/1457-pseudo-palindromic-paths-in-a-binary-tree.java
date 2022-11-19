/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int helper(TreeNode root, int[] freqMap) {
        if(root == null) return 0;
        freqMap[root.val]++;
        if(root.left == null && root.right == null) {
            int oddCount = 0;
            for(int i=1;i<10;i++) {
                if(freqMap[i] % 2 != 0) oddCount++;
                if(oddCount > 1) {
                    freqMap[root.val]--;
                    return 0;
                }
            }
            freqMap[root.val]--;
            return 1;
        }
        int res = helper(root.left, freqMap) + helper(root.right, freqMap);
        freqMap[root.val]--;
        return res;
    }
    public int pseudoPalindromicPaths (TreeNode root) {
        int[] freqMap = new int[10];
        return helper(root, freqMap);
    }
}