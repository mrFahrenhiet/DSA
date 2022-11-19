class Solution {
    private boolean isPalindrome(String str) {
        int left = 0, right = str.length() - 1;
        while(left < right) {
            if(str.charAt(left) != str.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }
    private void helper(String s, int i, List<String> arr, List<List<String>> res) {
        if(i >= s.length()) {
            res.add(new ArrayList<String>(arr));
            return;
        }
        for(int j=i;j<s.length();j++) {
            if(isPalindrome(s.substring(i, j+1))) {
                arr.add(new String(s.substring(i, j+1)));
                helper(s, j+1, arr, res);
                arr.remove(arr.size()-1);
            }
        }
        return;
    }
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> arr = new ArrayList<String>();
        helper(s, 0, arr, res);
        return res;
    }
}