class Solution {
    private List<List<String>> res;
    
    private boolean isPalindrome(String s) {
        for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if(s.charAt(i) != s.charAt(j)) return false;
        }
        
        return true;
    }
    
    private void helper(String s, List<String> temp, int i) {
        if(i >= s.length()) {
            res.add(new ArrayList<String>(temp));
            return;
        }
        
        for(int j = i; j < s.length(); j++) {
            String subStr = s.substring(i, j+1);
            if(this.isPalindrome(subStr)) {
                temp.add(subStr);
                helper(s, temp, j+1);
                temp.remove(temp.size() - 1);
            }
        }
        
        return;
    }
    public List<List<String>> partition(String s) {
        res = new ArrayList<>();
        List<String> temp = new ArrayList<String>();
        
        helper(s, temp, 0);
        
        return res;
    }
}